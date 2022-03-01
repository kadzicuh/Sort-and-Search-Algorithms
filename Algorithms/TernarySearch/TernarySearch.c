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

#include "TernarySearch.h"

int ternarySearch(int arr[], const int left, const int right, const int value)
{
    if (right >= left)
    {
        int midOne = left + (right - left) / 3;
        int midTwo = midOne + (right - left) / 3;

        if (arr[midOne] == value) return midOne;

        if (arr[midTwo] == value) return midTwo;

        if (arr[midOne] > value) return ternarySearch(arr, left, midOne - 1, value);

        if (arr[midTwo] < value) return ternarySearch(arr, midTwo + 1, right, value);

        return ternarySearch(arr, midOne + 1, midTwo - 1, value);
    }
    return -1;
}