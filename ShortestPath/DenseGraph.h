//
//  DenseGraph.h
//  ShortestPath
//
//  Created by yufenZ on 2020/3/4.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef DenseGraph_h
#define DenseGraph_h

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
using namespace std;

template <typename Weight>
class denseGraph{
private:
    int n, m; // 节点数和边数
    bool directed; // 是否为有向图
    vector<vector<Edge<Weight> *>> g; // 图的具体数据
    
public:
    //构造函数
    denseGraph(int n, bool directed){
        assert(n>=0);
        this->n = n;
        this->m = 0;
        this->directed = directed;
        g = vector<vector<Edge<Weight> *>>(n, vector<Edge<Weight> *>(n, NULL));
    }
    // 析构函数
    ~denseGraph(){
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(g[i][j] != NULL)
                    delete g[i][j];
    }
    int V(){return n;} // 返回节点个数
    int E(){return m;} // 返回边的个数
    //向图添加一个边
    void addEdge(int v, int w, Weight weight){
        assert(v>=0 && v<n);
        assert(w>=0 && w<n);
        //判断连个顶点之间是否有边，有就删除
        if(hasEdge(v, w)){
            delete g[v][w];
            if(v!=w && !directed)
                delete g[w][v];
            m --;
        }
        
        g[v][w] = new Edge<Weight>(v, w, weight);
        if(v!=w && !directed)
            g[w][v] = new Edge<Weight>(w, v, weight);
        m ++;
    }
    //验证图中是否有v，w的边
    bool hasEdge(int v, int w){
        assert(v>=0 && v<n);
        assert(w>=0 && w<n);
        return g[v][w] != NULL;
    }
    //显示图的信息
    void show(){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                if(g[i][j])
                    cout<<g[i][j]->wt()<<"\t";
                else
                    cout<<"NULL\t";
            cout<<endl;
        }
    }
    
    //邻边迭代器，传入一个图和一个顶点
    //迭代在这个图中和这个顶点相连的所有顶点
    class adjIterator{
    private:
        denseGraph &G;
        int v;
        int index;
        
    public:
        //构造函数
        adjIterator(denseGraph &graph, int v):G(graph){
            assert(v>=0 && v<G.n);
            this->v = v;
            this->index = -1;
        }
        //析构函数
        ~adjIterator(){}
        //返回图G中与顶点v相连的第一个顶点
        Edge<Weight>* begin(){
            index = -1;
            return next();
        }
        //返回图G中与顶点v相连的下一个顶点
        Edge<Weight>* next(){
            for(index += 1; index<G.V(); index ++)
                if(G.g[v][index])
                    return G.g[v][index];
            return NULL;
        }
        //判断是否已经迭代完所有顶点
        bool end(){
            return index >= G.V();
        }
    };
    
};

#endif /* DenseGraph_h */
