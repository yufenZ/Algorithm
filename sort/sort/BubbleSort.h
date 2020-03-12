//
//  BubbleSort.h
//  sort
//  冒泡排序
//  Created by yufenZ on 2020/2/18.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef BubbleSort_h
#define BubbleSort_h
#include <algorithm>
template<typename T>
void bubbleSort(T arr[], int n){
    for(int i=n-1; i>=0; i--){
        bool exchange = false;
        for (int j=0; j<i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                exchange = true;
            }
        }
        if(!exchange)
            break;
    }
    return;
}

#endif /* BubbleSort_h */
