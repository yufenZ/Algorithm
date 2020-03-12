//
//  quicksort.h
//  sort
//  快速排序
//  Created by yufenZ on 2020/2/18.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef quicksort_h
#define quicksort_h
#include <algorithm>
#include <iostream>
#include "InsertionSort.h"
using namespace std;

template<typename T>
int __partition(T arr[], int l, int r){
    T v = arr[l];
    int j=l;
    for(int i=l+1; i<=r; i++)
        if(arr[i]<v){
            j ++;
            swap(arr[j], arr[i]);
        }
    swap(arr[l], arr[j]);
    return j;
}

template<typename T>
void __quickSort(T arr[], int l, int r){
    if(r-l < 15){
        insertionSort(arr, l, r);
        return;
    }
    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}

template<typename T>
void quickSort(T arr[], int n){
    __quickSort(arr, 0, n-1);
}

#endif /* quicksort_h */
