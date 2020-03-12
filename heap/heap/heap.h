//
//  heap.h
//  heap
//  定义最大堆
//  Created by yufenZ on 2020/2/20.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef heap_h
#define heap_h

#include <iostream>
#include <algorithm>
using namespace std;

//定义堆类
template<typename Item>
class MaxHeap{
    
private:
    Item* data;
    int count;
    int capacity;
    void shiftup(int k){
        while(k>1 && data[k/2]<data[k]){
            swap(data[k/2], data[k]);
            k /= 2;
        }
    }
    
    void shiftDown(int k){
        while(2*k <= count){
            int j = 2*k;
            if(j+1 <= count && data[j+1] > data[j])
                j++;
            if(data[k]>=data[j])
                break;
            swap(data[k], data[j]);
            k = j;
        }
    }
    
public:
    //构造函数
    MaxHeap(int capacity){
        data = new Item[capacity+1];
        count = 0;
        this->capacity = capacity;
    }
    
    MaxHeap(Item arr[], int n){
        capacity = n;
        data = new Item[capacity+1];
        for(int i=0; i<n; i++)
            data[i+1] = arr[i];
        count = n;
        for (int i=count/2; i>=1; i--)
            shiftDown(i);
    }
    //析构函数
    ~MaxHeap(){
        delete [] data;
    }
    
    int size(){
        return count;
    }
    
    bool isEmpty(){
        return count == 0;
    }
    //向最大堆中插入一个新元素item
    void insert(Item item){
        data[count+1] = item;
        count++;
        shiftup(count);
    }
    //从最大堆中取出堆顶元素，即堆中所存储的最大数据
    Item extractMax(){
        Item ret = data[1];
        swap(data[1], data[count]);
        count --;
        shiftDown(1);
        return ret;
    }
};

#endif /* heap_h */
