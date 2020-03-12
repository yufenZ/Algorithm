//
//  maxindexheap.h
//  heap
//  最大索引堆
//  Created by yufenZ on 2020/2/21.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef maxindexheap_h
#define maxindexheap_h

#include <iostream>
using namespace std;

template<typename Item>
class IndexMaxHeap{
private:
    Item* data;
    int* indexes;
    int count;
    int capacity;
    
    void shiftUp(int k){
        while(k>1 && data[indexes[k/2]]<data[indexes[k]]){
            swap(indexes[k/2], indexes[k]);
            k /= 2;
        }
    }
    
    void shiftDown(int k){
        while(2*k <= count){
            int j = 2*k;
            if(j+1<=count && data[indexes[j+1]]>data[indexes[j]])
                j += 1;
            if (data[indexes[k]] >= data[indexes[j]])
                break;
            swap(indexes[k], indexes[j]);
            k = j;
        }
    }
public:
    IndexMaxHeap(int capacity){
        data = new Item[capacity+1];
        indexes = new int[capacity+1];
        count = 0;
        this->capacity = capacity;
    }
    ~IndexMaxHeap(){
        delete [] data;
        delete [] indexes;
    }
    int size(){
        return count;
    }
    bool isEmpty(){
        return count==0;
    }
    //在索引为i的位置添加元素item
    void insert(int i, Item item){
        i += 1; //用户索引从0开始，堆索引从1开始
        data[i] = item;
        indexes[count+1] = i;
        count++;
        shiftUp(count);
    }
    //从最大索引堆中推出堆顶元素
    Item extracMax(){
        Item ret = data[indexes[1]];
        swap(indexes[1], indexes[count]);
        count--;
        shiftDown(1);
        return ret;
    }
    //从最大索引堆中取出堆顶元素的索引
    int extracMacIndex(){
        int ret = indexes[1]-1;
        swap(indexes[1], indexes[count]);
        count--;
        shiftDown(1);
        return ret;
    }
    //将最大索引堆中索引为i的元素修改为newItem
    void change(int i, Item newItem){
        i += 1;
        data[i] = newItem;
        for(int j=1; j<=count; j++)
            if(indexes[j] == i){
                shiftUp(j);
                shiftDown(j);
                return;
            }
    }
    
}

#endif /* maxindexheap_h */
