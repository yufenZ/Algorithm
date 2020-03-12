//
//  UF.h
//  Mininum-Tree
//  并查集
//  Created by yufenZ on 2020/3/3.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef UF_h
#define UF_h

#include <iostream>
#include <cassert>
using namespace std;

class UnionFind{
private:
    int* rank;
    int* parent;//parent[i]表示第i个元素所指向的父亲节点
    int count;
public:
    UnionFind(int count){
        parent = new int[count];
        rank = new int[count];
        this->count = count;
        for(int i=0; i<count; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    ~UnionFind(){
        delete [] parent;
        delete [] rank;
    }
    //查找过程，查找元素p对应的集合编号
    int find(int p){
        assert(p>=0 && p<count);
        while(p!=parent[p]){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    //查看元素p和元素q是否属于同一个集合
    bool isConnected(int p, int q){
        return find(p) == find(q);
    }
    //将两个集合合并为一个集合
    void unionElement(int p, int q){
        int pRoot = find(p);
        int qRoot = find(q);
        if(pRoot == qRoot)
            return;
        //根据两个元素所在树的元素个数不同判断合并方向
        if(rank[pRoot] < rank[qRoot])
            parent[pRoot] = qRoot;
        else if(rank[pRoot] > rank[qRoot])
            parent[qRoot] = pRoot;
        else{
            parent[pRoot] = qRoot;
            rank[qRoot] += 1;
        }
    }
};

#endif /* UF_h */
