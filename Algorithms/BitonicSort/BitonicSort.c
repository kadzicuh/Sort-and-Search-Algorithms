/*
MIT License

Copyright (c) 2022 kadzicu

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "BitonicSort.h"

void bitonicMerge(int arr[], const int low, const int cnt, const int dir)
{
	if (cnt > 1)
	{
		int k = cnt / 2;

		for (int i = low; i < low + k; i++)
			if (dir == (arr[i] > arr[i + k]))
				swap(&arr[i], &arr[i + k]);

		bitonicMerge(arr, low, k, dir);
		bitonicMerge(arr, low + k, k, dir);
	}
}

void bitonicSort(int arr[], const int low, const int cnt, const int dir)
{
	if (cnt > 1)
	{
		int k = cnt / 2;

		bitonicSort(arr, low, k, 1);
		bitonicSort(arr, low + k, k, 0);
		bitonicMerge(arr, low, cnt, dir);
	}
}