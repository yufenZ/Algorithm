//
//  SorthTestHelper.h
//  heap
//
//  Created by yufenZ on 2020/2/21.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef SorthTestHelper_h
#define SorthTestHelper_h

//排序算法测试代码

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;

namespace SortTestHelper{
    // 生成有n个元素的随机数组
    int *generateRA(int n, int range_l, int range_r){
        int *arr = new int[n];
        //srand(time(NULL));
        for(int i=0; i<n; i++){
            arr[i] = rand() % (range_r - range_l + 1) + range_l;
        }
        return arr;
    }
    
    //拷贝数组到新数组
    int *copyArray(int a[], int n){
        int *arr = new int[n];
        copy(a, a+n, arr);
        return arr;
    }
    
    //打印数组内容
    template<typename T>
    void printArray(T arr[], int n){
        for (int i=0; i<n; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        return;
    }
    
    //判断arr是否有序
    template<typename T>
    bool isSorted(T arr[], int n){
        for(int i=0; i<n-1; i++)
            if(arr[i] > arr[i+1])
                return false;
        return true;
    }
    
    //测试排序算法排序数组所得正确结果的算法运行时间
    template<typename T>
    void testSort(const string &sortName, void (*sort)(T[], int), T arr[], int n){
        clock_t startTime = clock();
        sort(arr, n);
        clock_t stopTime = clock();
        cout<<sortName<<":"<<double(stopTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
        cout<<isSorted(arr, n)<<endl;
        return;
    }
}

#endif /* SorthTestHelper_h */
