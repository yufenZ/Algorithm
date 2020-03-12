//
//  LazyPrimMST.h
//  Mininum-Tree
//
//  Created by yufenZ on 2020/3/3.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef LazyPrimMST_h
#define LazyPrimMST_h

#include <iostream>
#include <cassert>
#include <vector>
#include "Edge.h"
#include "MinHeap.h"
using namespace std;

template <typename Graph, typename Weight>
class LazyPrimMST{
private:
    Graph &G;// 图的引用
    minHeap<Edge<Weight>> pq; //最小堆
    bool *marked; // 标记节点是否被访问
    vector<Edge<Weight>> mst;//最小生成树所包含的边
    Weight mstWeight;//最小生成树的权值
    
    void visit(int v){
        assert(!marked[v]);
        marked[v] = true;
        
        //将节点v相连的未访问的边放入最小堆
        typename Graph::adjIterator adj(G, v);
        for(Edge<Weight>* e=adj.begin(); !adj.end(); e = adj.next())
            if(!marked[e->other(v)])
                pq.insert(*e);
    }
public:
    LazyPrimMST(Graph &graph):G(graph), pq(minHeap<Edge<Weight>>(G.E())){
        marked = new bool[G.V()];
        for(int i=0; i<G.V(); i++)
            marked[i] = false;
        mst.clear();
        
        //Lazy Prim;
        visit(0);
        while(!pq.isEmpty()){
            //使用最小堆找出已经访问的边中权值最小的边
            Edge<Weight> e = pq.extractMin();
            //如果这条边的两端都已经访问过，则扔掉这条边
            if(marked[e.v()] == marked[e.w()])
                continue;
            //否则，这条边应在最小生成树中
            mst.push_back(e);
            //访问这条边连接的还没有被访问过的节点
            if(!marked[e.v()])
                visit(e.v());
            else
                visit(e.w());
        }
        //计算最小生成树权值
        mstWeight = mst[0].wt();
        for(int i=1; i<mst.size(); i++)
            mstWeight += mst[i].wt();
    }
    //析构函数
    ~LazyPrimMST(){
        delete[] marked;
    }
    //返回最小生成树所有的边
    vector<Edge<Weight>> mstEdge(){
        return mst;
    }
    //返回最小生成树的权值
    Weight result(){
        return mstWeight;
    }
};

#endif /* LazyPrimMST_h */
