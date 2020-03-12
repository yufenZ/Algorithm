//
//  Path.h
//  Graph_Basis
//  路径查询
//  Created by yufenZ on 2020/3/2.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef Path_h
#define Path_h

#include <vector>
#include <stack>
#include <iostream>
#include <cassert>
using namespace std;

template <typename Graph>
class Path{
private:
    Graph &G;
    bool *visited; //记录是否被访问过
    int *from; // 记录路径
    int s; //起始点
    //寻路算法
    void dfs(int v){
        visited[v] = true;
        typename Graph::adjIterator adj(G, v);
        for(int i=adj.begin(); !adj.end(); i=adj.next()){
            if(!visited[i]){
                from[i] = v;
                dfs(i);
            }
        }
    }
public:
    //构造函数
    Path(Graph &graph, int s):G(graph){
        assert(s>=0 && s<G.V());
        visited = new bool[G.V()];
        from = new int[G.V()];
        for(int i=0; i<G.V(); i++){
            visited[i] = false;
            from[i] = -1;
        }
        this->s = s;
        //寻路算法
        dfs(s);
    }
    ~Path(){
        delete [] visited;
        delete [] from;
    }
    //查询s，w是否有路径
    bool hasPath(int w){
        assert(w>=0 && w<G.V());
        return visited[w];
    }
    //查询从s到w的路径，存放在vec中
    //采用先进栈，后进向量的方法
    void searchpath(int w, vector<int> &vec){
        assert(hasPath(w));
        stack<int> s;
        int p=w;
        while(p != -1){
            s.push(p);
            p = from[p];
        }
        
        vec.clear();
        while(!s.empty()){
            vec.push_back(s.top());
            s.pop();
        }
    }
    //打印路径
    void show(int w){
        assert(hasPath(w));
        vector<int> vec;
        searchpath(w, vec);
        for(int i=0; i<vec.size(); i++){
            cout<<vec[i];
            if(i == vec.size()-1)
                cout<<endl;
            else
                cout<<"->";
        }
    }
};

#endif /* Path_h */
