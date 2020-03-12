//
//  quickSort3.h
//  sort
//  3路快速排序，特别适用于当序列中有大量重复元素时
//  Created by yufenZ on 2020/2/19.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef quickSort3_h
#define quickSort3_h
#include <iostream>
#include <algorithm>
#include "InsertionSort.h"
using namespace std;

template<typename T>
void __quicksort3(T arr[], int l, int r){
    if(r-l < 15){
        insertionSort(arr, l, r);
        return;
    }
    
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    int lt = l;
    int gt = r+1;
    int i = l+1;
    while(i<gt){
        if(arr[i]<v){
            swap(arr[i], arr[lt+1]);
            i++;
            lt++;
        }
        else if(arr[i] > v){
            swap(arr[i], arr[gt-1]);
            gt--;
        }
        else{
            i++;
        }
    }
    swap(arr[l], arr[lt]);
    __quicksort3(arr, l, lt-1);
    __quicksort3(arr, gt, r);
}

template<typename T>
void quicksort3(T arr[], int n){
    __quicksort3(arr, 0, n-1);
}

#endif /* quickSort3_h */
