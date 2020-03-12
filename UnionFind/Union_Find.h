//
//  Union_Find.h
//  UnionFind/
//  并查集，两个功能：1、将两个元素所在的集合并在一起；2、查看两个元素是否属于一个集合
//  最基础的并查集
//  Created by yufenZ on 2020/3/1.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef Union_Find_h
#define Union_Find_h

#include <iostream>
#include <cassert>
using namespace std;

namespace UF1 {
    class unionFind{
    private:
        int *id;
        int count;
    public:
        //构造函数
        unionFind(int n){
            count = n;
            id = new int[n];
            for(int i=0; i<n; i++)
                id[i] = i;
        }
        //析构函数
        ~unionFind(){
            delete [] id;
        }
        //查找过程，查找元素p所对应的集合编号
        int find(int p){
            assert(p >= 0 && p < count);
            return id[p];
        }
        //查看元素p和q是否属于一个集合
        bool isConnected(int p, int q){
            return find(p) == find(q);
        }
        //合并元素p和元素q所属的集合
        void unionElements(int p, int q){
            int pId = find(p);
            int qId = find(q);
            if(pId == qId)
                return;
            for (int i=0; i<count; i++)
                if(id[i] == pId)
                    id[i] = qId;
        }
    };
}

#endif /* Union_Find_h */
