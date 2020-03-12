//
//  Union_Find2.h
//  UnionFind
//  利用树结构构建并查表
//  Created by yufenZ on 2020/3/1.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef Union_Find2_h
#define Union_Find2_h

#include <cassert>
using namespace std;
//第二个版本的UnionFind，使用一个数组构建一棵指向父节点的树
//parent[i]表示第i个元素指向的父节点
namespace UF2 {
    class unionFind{
    private:
        int *parent;
        int count;
    public:
        //构造函数
        unionFind(int n){
            parent = new int[n];
            this->count = n;
            for(int i=0; i<count;i++)
                parent[i] = i;
        }
        //析构函数
        ~unionFind(){
            delete [] parent;
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
        //暴力合并，指定一个指向另一个
        void unionElements(int p, int q){
            int pRoot = find(p);
            int qRoot = find(q);
            if (pRoot == qRoot)
                return;
            parent[p] = qRoot;
        }
    };
}

#endif /* Union_Find2_h */
