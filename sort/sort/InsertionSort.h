//
//  InsertionSort.h
//  sort
//  插入排序
//  Created by yufenZ on 2020/2/18.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef InsertionSort_h
#define InsertionSort_h

//对整个数组进行快速排序
template<typename T>
void insertionSort(T arr[], int n){
    for(int i=1; i<n; i++){
        T e = arr[i];
        int j;
        for (j=i; j>0 && arr[j-1]>e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }
    return;
}

//对数组的特定区间范围内进行快速排序
template<typename T>
void insertionSort(T arr[], int l, int r){
    for (int  i=l+1; i <= r; i++){
        T e = arr[i];
        int j;
        for(j = i; j > l && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }
    return;
}

#endif /* InsertionSort_h */
