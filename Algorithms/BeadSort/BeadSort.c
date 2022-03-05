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

#include "BeadSort.h"

void beadSort(int arr[], const int size)
{
    int i, max;

    for (i = 1, max = arr[0]; i < size; i++)
        if (arr[i] > max)
            max = arr[i];

    unsigned char* beads = calloc(1, max * size);
    int j;

    for (i = 0; i < size; i++)
        for (j = 0; j < arr[i]; j++)
            beads[i * max + j] = 1;

    int sum;

    for (j = 0; j < max; j++)
    {
        for (sum = i = 0; i < size; i++)
        {
            sum += beads[i * max + j];
            beads[i * max + j] = 0;
        }

        for (i = size - sum; i < size; i++)
            beads[i * max + j] = 1;
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < max && beads[i * max + j]; j++);
        arr[i] = j;
    }
    free(beads);
}