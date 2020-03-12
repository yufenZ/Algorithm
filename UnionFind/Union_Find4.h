//
//  Union_Find4.h
//  UnionFind
//
//  Created by yufenZ on 2020/3/1.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef Union_Find4_h
#define Union_Find4_h

#include <cassert>
using namespace std;
//第四个版本的UnionFind，使用一个数组构建一棵指向父节点的树
//parent[i]表示第i个元素指向的父节点
namespace UF4 {
    class unionFind{
    private:
        int *parent;
        int *rank; //size
        int count;
    public:
        //构造函数
        unionFind(int n){
            parent = new int[n];
            rank = new int[n];
            this->count = n;
            for(int i=0; i<count; i++){
                parent[i] = i;
                rank[i] = 1;
            }
        }
        //析构函数
        ~unionFind(){
            delete [] parent;
            delete [] rank;
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
        //层树少的合并到层数多的
        void unionElements(int p, int q){
            int pRoot = find(p);
            int qRoot = find(q);
            if (pRoot == qRoot)
                return;
            
            if(rank[pRoot] < rank[qRoot]){
                parent[pRoot] = qRoot;
            }
            else if (rank[pRoot] > rank[qRoot]){
                parent[qRoot] = pRoot;
            }
            else{
                parent[pRoot] = qRoot;
                rank[qRoot] += 1;
            }
        }
    };
}
#endif /* Union_Find4_h */
