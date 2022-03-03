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

#include "ExponentialSearch.h"

int binaryySearch(int arr[], const int left, const int right, const int value)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == value) return mid;

        if (arr[mid] > value) return binaryySearch(arr, left, mid - 1, value);

        return binaryySearch(arr, mid + 1, right, value);
    }
    return -1;
}

int exponentialSearch(int arr[], int size, int value)
{
    if (arr[0] == value) return 0;

    int i = 1;

    while (i < size && arr[i] <= value)
        i = i * 2;

    return binaryySearch(arr, i / 2, minn(i, size - 1), value);
}