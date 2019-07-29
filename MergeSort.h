#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//¹é²¢ÅÅĞòµİ¹éËã·¨
void Merge(int *a,int left,int right,int *tmp,int mid)
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1];
			++begin1;
		}
		else
		{
			tmp[i++] = a[begin2];
			++begin2;
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1];
		++begin1;
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2];
		++begin2;
	}
	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}

void _MergeSort(int *a, int left, int right, int *tmp)
{
	int mid = left + (right - left) / 2;
	if (left == right)
		return;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	Merge(a, left, right, tmp,mid);
}

void MergeSort(int *a, int n)
{
	int *tmp = (int *)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}



//¹é²¢ÅÅĞò·Çµİ¹éËã·¨
void MergeSortNor(int *a, int n)
{

	int *tmp = (int*)malloc(sizeof(int)*n);
	int gap = 1;
	while (gap < n)
	{
		for (int begin = 0;begin < n;begin += gap * 2)
		{
			int begin1 = begin;
			int end1 = begin + gap - 1;
			if (end1 >= n)
			{
				end1 = n - 1;
			}
			int begin2 = begin + gap;
			int end2 = begin + 2 * gap - 1;
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			int index = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[index++] = a[begin1++];
				}
				else
				{
					tmp[index++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[index++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[index++] = a[begin2++];
			}
		}
		memcpy(a, tmp, sizeof(int)*(n));
		gap *= 2;
	}
	free(tmp);
}
