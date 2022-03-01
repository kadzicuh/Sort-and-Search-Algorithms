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

#include <stdio.h>

//#include "BubbleSort/BubbleSort.h"
//#include "SelectionSort/SelectionSort.h"
//#include "InsertionSort/InsertionSort.h"
//#include "MergeSort/MergeSort.h"
//#include "QuickSort/QuickSort.h"
//#include "CountingSort/CountingSort.h"
//#include "RadixSort/RadixSort.h"
//#include "HeapSort/HeapSort.h"
//#include "ShellSort/ShellSort.h"
//#include "LinearSearch/LinearSearch.h"
//#include "BinarySearch/BinarySearch.h"
//#include "InterpolationSearch/InterpolationSearch.h"

void printArr(int arr[], const int size) 
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() 
{
    int data[] = { 9, 2, 6, 8, 3, 7, 1 };

    int size = sizeof(data) / sizeof(data[0]);

    //bubbleSort(data, size);
    //selectionSort(data, size);
    //insertionSort(data, size);
    //mergeSort(data, 0 , size - 1);
    //quickSort(data, 0, size - 1);
    //countingSort(data, size);
    //radixSort(data, size);
    //heapSort(data, size);
    //shellSort(data, size);

    //printf("%d ",linearSearch(data, size, 8));
    //printf("%d ", binarySearch(data, 8, 0, size - 1));
    //printf("%d ", interpolationSearch(data, 0, size - 1, 8));

    //printArr(data, size);
}