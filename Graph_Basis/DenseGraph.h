//
//  DenseGraph.h
//  Graph_Basis
//  邻接矩阵表示稠密图
//  Created by yufenZ on 2020/3/2.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef DenseGraph_h
#define DenseGraph_h

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class denseGraph{
private:
    int n, m; // 节点数和边数
    bool directed; // 是否为有向图
    vector<vector<bool>> g; // 图的具体数据
    
public:
    //构造函数
    denseGraph(int n, bool directed){
        assert(n>=0);
        this->n = n;
        this->m = 0;
        this->directed = directed;
        g = vector<vector<bool>>(n, vector<bool>(n, false));
    }
    // 析构函数
    ~denseGraph(){}
    int V(){return n;} // 返回节点个数
    int E(){return m;} // 返回边的个数
    //向图添加一个边
    void addEdge(int v, int w){
        assert(v>=0 && v<n);
        assert(w>=0 && w<n);
        
        if(hasEdge(v, w))
            return;
        g[v][w] = true;
        if(!directed)
            g[w][v] = true;
        m ++;
    }
    //验证图中是否有v，w的边
    bool hasEdge(int v, int w){
        assert(v>=0 && v<n);
        assert(w>=0 && w<n);
        return g[v][w];
    }
    //显示图的信息
    void show(){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                cout<<g[i][j]<<" ";
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
        int begin(){
            index = -1;
            return next();
        }
        //返回图G中与顶点v相连的下一个顶点
        int next(){
            for(index += 1; index<G.V(); index ++)
                if(G.g[v][index])
                    return index;
            return -1;
        }
        //判断是否已经迭代完所有顶点
        bool end(){
            return index >= G.V();
        }
    };
    
};

#endif /* DenseGraph_h */
