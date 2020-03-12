//
//  Union_Find3.h
//  UnionFind
//
//  Created by yufenZ on 2020/3/1.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef Union_Find3_h
#define Union_Find3_h

#include <cassert>
using namespace std;
//第三个版本的UnionFind，使用一个数组构建一棵指向父节点的树
//parent[i]表示第i个元素指向的父节点
namespace UF3 {
    class unionFind{
    private:
        int *parent;
        int *sz; //size
        int count;
    public:
        //构造函数
        unionFind(int n){
            parent = new int[n];
            sz = new int[n];
            this->count = n;
            for(int i=0; i<count; i++){
                parent[i] = i;
                sz[i] = 1;
            }
        }
        //析构函数
        ~unionFind(){
            delete [] parent;
            delete [] sz;
        }
        //查找过程，查找元素对应的集合编号
        int find(int p){
            assert(p >= 0 && p < count);
            while(p != parent[p])
                p = parent[p];
            return p;
        }
        //判断元素p和元素q是否属于一个集合
        bool isConnected(int p, int q){
            return find(p) == find(q);
        }
        //合并元素p和元素q的集合
        //元素少的合并到元素多的
        void unionElements(int p, int q){
            int pRoot = find(p);
            int qRoot = find(q);
            if (pRoot == qRoot)
                return;
            
            if(sz[pRoot] < sz[qRoot]){
                parent[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            }
            else{
                parent[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }
        }
    };
}

#endif /* Union_Find3_h */
