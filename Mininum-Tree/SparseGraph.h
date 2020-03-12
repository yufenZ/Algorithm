//
//  SparseGraph.h
//  Mininum-Tree
//
//  Created by yufenZ on 2020/3/3.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef SparseGraph_h
#define SparseGraph_h

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
using namespace std;

template <typename Weight>
class sparseGraph{
private:
    int n, m;
    bool directed;
    vector<vector<Edge<Weight> *>> g;
public:
    //构造函数
    sparseGraph(int n, bool directed){
        assert(n>=0);
        this->n = n;
        this->m = 0;
        this->directed = directed;
        g = vector<vector<Edge<Weight> *>>(n, vector<Edge<Weight> *>());
    }
    //析构函数
    ~sparseGraph(){
        for(int i=0; i<n; i++)
            for(int j=0; j<g[i].size(); j++)
                delete g[i][j];
    }
    //返回节点个数
    int V(){return n;}
    //返回边的个数
    int E(){return m;}
    //向图添加一条边,不考虑平行边
    void addEdge(int v, int w, Weight weight){
        assert(v>=0 && v<n);
        assert(w>=0 && w<n);
        
        g[v].push_back(new Edge<Weight>(v, w, weight));
        if(v!=w && !directed)
            g[w].push_back(new Edge<Weight>(w, v, weight));
        m ++;
    }
    //验证图中是否有v，w的边
    bool hasEdge(int v, int w){
        assert(v>=0 && v<n);
        assert(w>=0 && w<n);
        
        for(int i=0; i<g[v].size(); i++)
            if(g[v][i]->other(v) == w)
                return true;
        return false;
    }
    
    //显示图的信息
    void show(){
        for(int i=0; i<n; i++){
            cout<<"vertex "<<i<<":  ";
            for(int j=0; j<g[i].size(); j++)
                cout<<"( to:"<<g[i][j]->w()<<",wt:"<<g[i][j]->wt()<<")\t";
            cout<<endl;
        }
    }
    
    class adjIterator{
    private:
        sparseGraph &G;
        int v;
        int index;
        
    public:
        adjIterator(sparseGraph &graph, int v):G(graph){
            this->v = v;
            this->index = 0;
        }
        ~adjIterator(){}
        //返回图中与v相连的第一个顶点
        Edge<Weight>* begin(){
            index = 0;
            if(G.g[v].size())
                return G.g[v][index];
            return NULL;
        }
        //返回图中与v相连的下一个顶点
        Edge<Weight>* next(){
            index += 1;
            if(index<G.g[v].size())
                return G.g[v][index];
            return NULL;
        }
        //判断是否迭代完所有顶点
        bool end(){
            return index >= G.g[v].size();
        }
    };
};

#endif /* SparseGraph_h */
