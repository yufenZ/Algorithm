//
//  PrimMST.h
//  Mininum-Tree
//  使用优化Prim算法实现最小生成树
//  Created by yufenZ on 2020/3/3.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef PrimMST_h
#define PrimMST_h

#include <iostream>
#include <cassert>
#include <vector>
#include "Edge.h"
#include "IndexMinHeap.h"
using namespace std;

template <typename Graph, typename Weight>
class PrimMST{
private:
    Graph &G;
    IndexMinHeap<Weight> ipq; //最小索引堆
    vector<Edge<Weight>*> edgeTo; //访问的点所对应的边
    bool* marked; //标记数组，记录节点i是否被访问
    vector<Edge<Weight>> mst; //最小生成树包含的所有边
    Weight mstWeight; //最小生成树的权值
    
    //访问节点v
    void visit(int v){
        assert(!marked[v]);
        marked[v] = true;
        
        //将和节点v相连接的未访问的另一端点，和与之相连接的边，放入最小索引堆
        typename Graph::adjIterator adj(G, v);
        for(Edge<Weight>* e=adj.begin(); !adj.end(); e=adj.next()){
            int w = e->other(v);
            //如果边的另一端点未被访问
            if(!marked[w]){
                //如果从未考虑过这个端点，直接加入索引堆
                if(!edgeTo[w]){
                    edgeTo[w] = e;
                    ipq.insert(w, e->wt());
                }
                //如果曾经考虑过，但现在的边比以前的边短，则进行替换
                else if(e->wt() < edgeTo[w]->wt()){
                    edgeTo[w] = e;
                    ipq.change(w, e->wt());
                }
            }
        }
    }
public:
    PrimMST(Graph &graph):G(graph), ipq(IndexMinHeap<Weight>(G.V())){
        assert(G.E() >= 1);
        marked = new bool[G.V()];
        for(int i=0; i<G.V(); i++){
            marked[i] = false;
            edgeTo.push_back(NULL);
        }
        mst.clear();
        //Prim算法
        visit(0);
        while (!ipq.isEmpty()) {
            //使用最小索引堆找出已经访问的边中权值最小的边
            //最小索引堆中存储的是点的索引，通过点的索引找到相应的边
            int v = ipq.extractMinIndex();
            assert(edgeTo[v]);
            mst.push_back(*edgeTo[v]);
            visit(v);
        }
        mstWeight = mst[0].wt();
        for(int i=1; i<mst.size(); i++)
            mstWeight += mst[i].wt();
    }
    ~PrimMST(){
        delete marked;
    }
    vector<Edge<Weight>> mstEdges(){
        return mst;
    }
    Weight result(){
        return mstWeight;
    }
};

#endif /* PrimMST_h */
