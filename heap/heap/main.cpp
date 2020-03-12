//
//  main.cpp
//  heap
//  堆
//  Created by yufenZ on 2020/2/20.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "heap.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SorthTestHelper.h"
#include "HeapSort.h"
using namespace std;

template<typename T>
void _shiftDown(T arr[], int n, int k){
    while(2*k+1<n){
        int j = 2*k+1;
        if(j+1<n && arr[j+1]>arr[j])
            j++;
        if(arr[k]>=arr[j])
            break;
        swap(arr[k], arr[j]);
        k=j;
    }
}

template<typename T>
void _shiftDown2(T arr[], int n, int k){
    T e = arr[k];
    while(2*k+1<n){
        int j = 2*k+1;
        if(j+1<n && arr[j+1]>arr[j])
            j++;
        if(e>arr[j])
            break;
        arr[k] = arr[j];
        k=j;
    }
    arr[k] = e;
}

//改进的堆排序，从索引0开始并且不用辅助空间
template<typename T>
void heapSort3(T arr[], int n){
    for(int i=(n-1-1/2); i>=0; i--)
        _shiftDown(arr, n, i);
    for(int i=n-1; i>0; i--){
        swap(arr[0], arr[i]);
        _shiftDown2(arr, i, 0);
    }
}

int main(int argc, const char * argv[]) {
    int n = 1000000;
    cout<<"Test for random array, size="<<n<<",random range[0,"<<n<<"]"<<endl;
    int* arr = SortTestHelper::generateRA(n, 0, n);
    int* arr1 = SortTestHelper::copyArray(arr, n);
    int* arr2 = SortTestHelper::copyArray(arr, n);
    int* arr3 = SortTestHelper::copyArray(arr, n);
    int* arr4 = SortTestHelper::copyArray(arr, n);
    int* arr5 = SortTestHelper::copyArray(arr, n);
    
    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Heap Sort", heapSort1, arr3, n);
    SortTestHelper::testSort("Heap Sort2", heapSort2, arr4, n);
    SortTestHelper::testSort("Heap Sort3", heapSort3, arr5, n);
    
    delete [] arr;
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    delete [] arr4;
    delete [] arr5;
    
    return 0;
}
