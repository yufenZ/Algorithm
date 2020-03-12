//
//  main.cpp
//  sort
//
//  Created by yufenZ on 2020/2/18.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#include <iostream>
// #include "Selection.h"
#include "SortTestHelper.h"
#include "InsertionSort.h"
// #include "BubbleSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "quicksort.h"
#include "quicksort2.h"
#include "quickSort3.h"
using namespace std;

int main(){
    int n = 20000;
    cout<<"Test for random array, size="<<n<<", random range [0,"<<n<<"]"<<endl;
    int *arr1 = SortTestHelper::generateRA(n, 0, n);
    int *arr2 = SortTestHelper::copyArray(arr1, n);
    // int *arr3 = SortTestHelper::copyArray(arr1, n);
    int *arr4 = SortTestHelper::copyArray(arr1, n);
    int *arr5 = SortTestHelper::copyArray(arr1, n);
    int *arr6 = SortTestHelper::copyArray(arr1, n);
    int *arr7 = SortTestHelper::copyArray(arr1, n);
    int *arr8 = SortTestHelper::copyArray(arr1, n);
    
    // SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    // SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr4, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr5, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr6, n);
    SortTestHelper::testSort("Quick Sort 2", quickSort2, arr7, n);
    SortTestHelper::testSort("Quick Sort 3", quicksort3, arr8, n);

    delete[] arr1;
    delete[] arr2;
    // delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    
    return 0;
}
