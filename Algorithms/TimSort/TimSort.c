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

#include "TimSort.h"

void timInsertion(int arr[], const int left, const int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        const int temp = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void timMerge(int arr[], const int left, const int mid, const int right)
{
    const int sizeArrLeft = mid - left + 1;
    const int sizeArrRight = right - mid;

    int* leftArr = (int*)malloc(sizeArrLeft * sizeof(int));
    int* rightArr = (int*)malloc(sizeArrRight * sizeof(int));

    for (int i = 0; i < sizeArrLeft; i++)
        leftArr[i] = arr[left + i];

    for (int i = 0; i < sizeArrRight; i++)
        rightArr[i] = arr[mid + 1 + i];

    int indexOfArrLeft = 0;
    int indexOfArrRight = 0;
    int indexOfMergedArr = left;

    while (indexOfArrLeft < sizeArrLeft && indexOfArrRight < sizeArrRight)
    {
        if (leftArr[indexOfArrLeft] <= rightArr[indexOfArrRight])
        {
            arr[indexOfMergedArr] = leftArr[indexOfArrLeft];
            ++indexOfArrLeft;
        }
        else
        {
            arr[indexOfMergedArr] = rightArr[indexOfArrRight];
            ++indexOfArrRight;
        }
        ++indexOfMergedArr;
    }

    while (indexOfArrLeft < sizeArrLeft)
    {
        arr[indexOfMergedArr] = leftArr[indexOfArrLeft];
        ++indexOfArrLeft;
        ++indexOfMergedArr;
    }

    while (indexOfArrRight < sizeArrRight)
    {
        arr[indexOfMergedArr] = rightArr[indexOfArrRight];
        ++indexOfArrRight;
        ++indexOfMergedArr;
    }
    free(leftArr);
    free(rightArr);
}

void timSort(int arr[], int size)
{
    const int run = 32;

    for (int i = 0; i < size; i += run)
        timInsertion(arr, i, minn((i + run - 1), (size - 1)));

    for (int size = run; size < size; size = 2 * size)
    {
        for (int left = 0; left < size; left += 2 * size)
        {
            const int mid = left + size - 1;
            const int right = minn((left + 2 * size - 1), (size - 1));

            if (mid < right)
                timMerge(arr, left, mid, right);
        }
    }
}