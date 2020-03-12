//
//  binary_search.h
//  Tree
//  用两种方法实现二分查找法
//  Created by yufenZ on 2020/2/28.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef binary_search_h
#define binary_search_h
//使用迭代方法实现二分查找法
template <typename T>
int binarySearch(T arr[], int n, T target){
    //在arr[l...r]中查找target
    int l=0, r=n-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            l = mid+1;
        else
            r = mid-1;
    }
    return -1;
}

//使用递归实现二分查找法
template <typename T>
int __binarySearch2(T arr[], int l, int r, T target){
    if(l>r)
        return -1;
    int mid = l+(r-l)/2;
    if(arr[mid] == target)
        return mid;
    else if(arr[mid] < target)
        return __binarySearch2(arr, mid+1, r, target);
    else
        return __binarySearch2(arr, l, mid-1, target);
}


template <typename T>
int binarySearch2(T arr[], int n, T target){
    return __binarySearch2(arr, 0, n-1, target);
}

#endif /* binary_search_h */
