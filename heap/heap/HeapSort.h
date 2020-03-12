//
//  HeapSort.h
//  heap
//  堆排序
//  Created by yufenZ on 2020/2/21.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef HeapSort_h
#define HeapSort_h
#include <iostream>
#include <algorithm>
#include "heap.h"
using namespace std;

//heapSort1, 将所有元素依次添加到堆里，在将所有元素从堆中依次取出来
//无论创建堆还是去除堆，时间复杂度都是O(nlogn)
//整个堆排序整体时间也是O(nlogn)
template<typename T>
void heapSort1(T arr[], int n){
    MaxHeap<T> maxheap = MaxHeap<T>(n);
    for(int i=0; i<n; i++)
        maxheap.insert(arr[i]);
    for(int i=n-1; i>=0; i--)
        arr[i] = maxheap.extractMax();
}

//heapSort2,借助我们的heapify过程创建堆
//此时，创建堆的时间复杂度是O(n)，将元素依次取出的时间复杂度是O(nlogn)
//堆排序的总时间复杂度还是O(nlogn)，但比上述的heapSort1性能更优
template<typename T>
void heapSort2(T arr[], int n){
    MaxHeap<T> maxheap2 = MaxHeap<T>(arr, n);
    for(int i=n-1; i>=0; i--)
        arr[i] = maxheap2.extractMax();
}

#endif /* HeapSort_h */
