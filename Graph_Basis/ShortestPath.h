//
//  ShortestPath.h
//  Graph_Basis
//  寻找无权图的最短路径
//  Created by yufenZ on 2020/3/2.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef ShortestPath_h
#define ShortestPath_h

#include <iostream>
#include <queue>
#include <vector>
#include <cassert>
#include <stack>
using namespace std;

template <typename Graph>
class shortestPath{
private:
    Graph &G;
    bool *visited; //记录是否被访问过
    int *from; // 记录路径
    int s; //起始点
    int *ord; //记录路径中节点的次序；ord[i]表示i节点在路径中的次序
public:
    //构造函数
    shortestPath(Graph &graph, int s):G(graph){
        assert(s>=0 && s<G.V());
        visited = new bool[G.V()];
        from = new int[G.V()];
        ord = new int[G.V()];
        for (int i=0; i<G.V(); i++){
            visited[i] = 0;
            from[i] = -1;
            ord[i] = -1;
        }
        this->s = s;
        
        //无向图最短路径算法，从s开始广度遍历整张图
        queue<int> q;
        q.push(s);
        visited[s] = true;
        ord[s] = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            
            typename Graph::adjIterator adj(G, v);
            for(int i=adj.begin(); !adj.end(); i=adj.next()){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                    from[i] = v;
                    ord[i] = ord[v] + 1;
                }
            }
        }
    }
    //析构函数
    ~shortestPath(){
        delete [] visited;
        delete [] from;
        delete [] ord;
    }
    //查询从s到w是否有路径
    bool hasPath(int w){
        assert(w>=0 && w<G.V());
        return visited[w];
    }
    //查询从s到w的路径，并存放在vec中
    void searchPath(int w, vector<int> &vec){
        assert(hasPath(w));
        stack<int> s;
        //通过from逆向寻找，并存放在栈中
        int p=w;
        while(p!=-1){
            s.push(p);
            p=from[p];
        }
        vec.clear();
        //从栈中找到路径存放在vec中
        while(!s.empty()){
            vec.push_back(s.top());
            s.pop();
        }
    }
    //打印从s到w的路径
    void show(int w){
        assert(hasPath(w));
        vector<int> vec;
        searchPath(w, vec);
        for(int i=0; i<vec.size(); i++){
            cout<<vec[i];
            if(i == vec.size()-1)
                cout<<endl;
            else
                cout<<"->";
        }
    }
    //查看最短路径长度；
    int length(int w){
        assert(hasPath(w));
        return ord[w];
    }
};


#endif /* ShortestPath_h */
