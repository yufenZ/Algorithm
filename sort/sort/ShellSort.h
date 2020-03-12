//
//  ShellSort.h
//  sort
//  希尔排序
//  Created by yufenZ on 2020/2/18.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef ShellSort_h
#define ShellSort_h

template<typename T>
void shellSort(T arr[], int n){
    int h = 1;
    while(h<n/3)
        h = 3 * h + 1;
    while(h >= 1){
        for (int i=h; i<n; i++){
            T e = arr[i];
            int j;
            for(j=i; j>=h && e<arr[j-h]; j-=h)
                arr[j] = arr[j-h];
            arr[j] = e;
        }
        h /= 3;
    }
    return;
}

#endif /* ShellSort_h */
