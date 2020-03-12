//
//  Selection.h
//  sort
//  选择排序
//  Created by yufenZ on 2020/2/18.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef Selection_h
#define Selection_h

#include<algorithm>
using namespace std;

template<typename T>
void selectionSort(T arr[], int n){
    for(int i=0; i<n; i++){
        int minindex = i;
        for(int j=i; j<n; j++){
            if(arr[j] < arr[minindex])
                minindex = j;
        }
        swap(arr[i], arr[minindex]);
    }
}

#endif /* Selection_h */
