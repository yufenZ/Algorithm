//
//  KruskalMST.h
//  Mininum-Tree
//  使用Kruskal算法构建最小生成树
//  Created by yufenZ on 2020/3/3.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef KruskalMST_h
#define KruskalMST_h

#include <iostream>
#include <vector>
#include "MinHeap.h"
#include "Edge.h"
#include "UF.h"
using namespace std;

template <typename Graph, typename Weight>
class KruskalMST{
private:
    vector<Edge<Weight>> mst;
    Weight mstWeight;
public:
    KruskalMST(Graph &graph){
        //将图中的所有边存放在最小堆中
        minHeap<Edge<Weight>> pq(graph.E());
        for(int i=0; i<graph.V(); i++){
            typename Graph::adjIterator adj(graph, i);
            for(Edge<Weight>* e=adj.begin(); !adj.end(); e=adj.next()){
                if(e->v() < e->w())
                    pq.insert(*e);
            }
        }
        //创建一个并查集，来查看已经访问的节点的联通情况
        UnionFind uf = UnionFind(graph.V());
        while(!pq.isEmpty() && mst.size()<graph.V()-1){
            //从最小堆中依次取出从小到大的边
            Edge<Weight> e = pq.extractMin();
            //如果取出的边两个端点是联通的，则构成环
            if(uf.isConnected(e.v(), e.w()))
                continue;
            
            //否则，将这条边添加到最小生成树，并标记两点联通
            mst.push_back(e);
            uf.unionElement(e.v(), e.w());
        }
        mstWeight = mst[0].wt();
        for(int i=1; i<mst.size(); i++)
            mstWeight += mst[i].wt();
    }
    ~KruskalMST(){}
    //返回最小树的所有边
    vector<Edge<Weight>> mstEdges(){
        return mst;
    }
    //返回最小树的权值
    Weight result(){
        return mstWeight;
    }
};


#endif /* KruskalMST_h */
