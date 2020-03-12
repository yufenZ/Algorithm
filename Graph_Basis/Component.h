//
//  Component.h
//  Graph_Basis
//  测试联通分量，判断两个顶点是否联通，计算有多少个联通域
//  Created by yufenZ on 2020/3/2.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef Component_h
#define Component_h
#include <iostream>
#include <cassert>
using namespace std;

template <typename Graph>
class component{
private:
    Graph &G;
    bool *visited; //记录每一个节点是否被访问过
    int ccount;
    int *id; // 记录节点属于哪一个联通域
    //图的深度优先遍历
    void dfs(int v){
        visited[v] = true;
        id[v] = ccount;
        typename Graph::adjIterator adj(G, v);
        for(int i=adj.begin(); !adj.end(); i=adj.next()){
            if(!visited[i])
                dfs(i);
        }
    }
public:
    component(Graph &graph):G(graph){
        visited = new bool[G.V()];
        id = new int[G.V()];
        ccount = 0;
        for(int i=0; i<G.V(); i++){
            visited[i] = false;
            id[i] = -1;
        }
        //求图的联通分量
        for(int i=0; i<G.V(); i++)
            if(!visited[i]){
                dfs(i);
                ccount ++;
            }
    }
    //析构函数
    ~component(){
        delete [] visited;
        delete [] id;
    }
    //返回图的联通分量个数
    int count(){
        return ccount;
    }
    //判断两个顶点是否联通
    bool isConnected(int v, int w){
        assert(v>=0 && v<G.V());
        assert(w>=0 && w<G.V());
        return id[v] == id[w];
    }
};

#endif /* Component_h */
