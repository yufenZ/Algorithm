//
//  MinHeap.h
//  Mininum-Tree
//  最小堆
//  Created by yufenZ on 2020/3/3.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef MinHeap_h
#define MinHeap_h

#include <algorithm>
#include <cassert>
using namespace std;

template <typename Item>
class minHeap{
private:
    Item *data;
    int count;
    int capacity;
    void shiftUp(int k){
        while(k>1 && data[k/2] > data[k]){
            swap(data[k/2], data[k]);
            k /= 2;
        }
    }
    
    void shiftDown(int k){
        while(2*k<=count){
            int j = 2*k;
            if(j+1<=count && data[j+1]<data[j])
                j ++;
            if(data[k]<=data[j])
                break;
            swap(data[k], data[j]);
            k=j;
        }
    }
public:
    //构造函数
    minHeap(int capacity){
        data = new Item[capacity+1];
        count = 0;
        this->capacity = capacity;
    }
    //通过一个给定数组构造最小堆
    minHeap(Item arr[], int n){
        data = new Item[n+1];
        capacity = n;
        for(int i=0; i<n; i++)
            data[i+1] = arr[i];
        count = n;
        for(int i=count/2; i>=1; i--)
            shiftDown(i);
    }
    //析构函数
    ~minHeap(){
        delete [] data;
    }
    //返回堆中的元素个数
    int size(){
        return count;
    }
    //判断堆是否为空
    bool isEmpty(){
        return count == 0;
    }
    //向最小堆插入一个新元素
    void insert(Item item){
        assert(count + 1 <= capacity);
        data[count+1] = item;
        shiftUp(count+1);
        count ++;
    }
    //从最小堆中取出堆顶元素
    Item extractMin(){
        assert(count>0);
        Item ret = data[1];
        swap(data[1], data[count]);
        count --;
        shiftDown(1);
        return ret;
    }
    //获取最小堆中的堆顶元素
    Item getMin(){
        assert(count > 0);
        return data[1];
    }
};

#endif /* MinHeap_h */
