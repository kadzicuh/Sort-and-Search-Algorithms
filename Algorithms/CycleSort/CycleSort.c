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

#include "CycleSort.h"

void cycleSort(int arr[], const int size)
{
    int writes = 0;

    for (int start = 0; start <= size - 2; start++) 
    {
        const int item = arr[start];
        int pos = start;

        for (int j = start + 1; j < size; j++)
            if (arr[j] < item)
                pos++;

        if (pos == start) continue;

        while (item == arr[pos])
            pos += 1;

        if (pos != start) 
        {
            swap(&item, &arr[pos]);
            writes++;
        }

        while (pos != start) 
        {
            pos = start;

            for (int i = start + 1; i < size; i++)
                if (arr[i] < item)
                    pos += 1;

            while (item == arr[pos])
                pos += 1;

            if (item != arr[pos]) 
            {
                swap(&item, &arr[pos]);
                writes++;
            }
        }
    }
}