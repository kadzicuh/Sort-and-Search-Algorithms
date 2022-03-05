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

#include "PermutationSort.h"

void printString(const char* arr[], const int size)
{
    for (int i = 0; i < size; i++)
        printf("%s ", arr[i]);
    printf("\n");
}

void permutationSort(char* arr, int size, int sizeM, int(*cmp)(const void*, const void*))
{
    char* p = 0;
    char* q = 0;

    while (TRUE)
    {
        for (p = arr + sizeM * (size - 1); p > arr; p = q)
            if (cmp(q = p - sizeM, p) > 0) break;

        if (p <= arr) break;

        for (p = arr + sizeM * (size - 1); p > q; p -= sizeM)
            if (cmp(q, p) > 0) break;

        swapString(p, q);

        for (q += sizeM, p = arr + sizeM * (size - 1); q < p; q += sizeM, p -= sizeM)
            swapString(p, q);
    }
}