//
//  Dijkstra.h
//  ShortestPath
//  Dijkstra算法求最短路径
//  Created by yufenZ on 2020/3/4.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef Dijkstra_h
#define Dijkstra_h

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include "Edge.h"
#include "IndexMinHeap.h"
using namespace std;

template <typename Graph, typename Weight>
class Dijkstra{
private:
    Graph &G;
    int s; //起始点
    Weight *distTo; //distTo[i]存储从起始点s到i的最短路径长度
    bool *marked; //标记数组，记录节点i是否被访问过
    vector<Edge<Weight>*> from; //from[i]记录最短路径中，到达i点的是哪条边
    
public:
    Dijkstra(Graph &graph, int s):G(graph){
        assert(s>=0 && s<G.V());
        this->s = s;
        distTo = new Weight[G.V()];
        marked = new bool[G.V()];
        for(int i=0; i<G.V(); i++){
            distTo[i] = Weight();
            marked[i] = false;
            from.push_back(NULL);
        }
        //使用索引堆记录当前找到的到达每个节点的最短距离
        IndexMinHeap<Weight> ipq(G.V());
        //对起始点进行初始化
        distTo[s] = Weight();
        from[s] = new Edge<Weight>(s, s, Weight());
        ipq.insert(s, distTo[s]);
        marked[s] = true;
        while(!ipq.isEmpty()){
            int v = ipq.extractMinIndex();
            //distTo[v]就是s到v的最短距离
            marked[v] = true;
            //对v的所有相邻节点进行遍历
            typename Graph::adjIterator adj(G, v);
            for(Edge<Weight>* e = adj.begin(); !adj.end(); e=adj.next()){
                int w = e->other(v);
                //如果从s到w的最短路径还没有找到
                if(!marked[w]){
                    if(from[w] == NULL || distTo[v]+e->wt() < distTo[w]){
                        distTo[w] = distTo[v]+e->wt();
                        from[w] = e;
                        if(ipq.contain(w))
                            ipq.change(w, distTo[w]);
                        else
                            ipq.insert(w, distTo[w]);
                    }
                }
            }
        }
    }
    //析构函数
    ~Dijkstra(){
        delete [] distTo;
        delete [] marked;
        delete from[s];
    }
    //返回从s到w的最短路径长度
    Weight shortestPathTo(int w){
        assert(w>=0 && w<G.V());
        assert(hasPathTo(w));
        return distTo[w];
    }
    //判断从s到w是否联通
    bool hasPathTo(int w){
        assert(w>=0 && w<G.V());
        return marked[w];
    }
    //寻找从s到w的最短路径，并存放在vec中
    void shortestpath(int w, vector<Edge<Weight>> &vec){
        assert(w>=0 && w<G.V());
        assert(hasPathTo(w));
        //通过from数组逆向查找从s到w的路径，存到栈中
        stack<Edge<Weight>* > s;
        Edge<Weight> *e = from[w];
        while (e->v() != this->s) {
            s.push(e);
            e = from[e->v()];
        }
        s.push(e);
        //从栈中依次取出元素，分到vec中
        while(!s.empty()){
            e = s.top();
            vec.push_back(*e);
            s.pop();
        }
    }
    //打印从s到w的路径
    void showPath(int w){
        assert(w>=0 && w<G.V());
        assert(hasPathTo(w));
        vector<Edge<Weight>> vec;
        shortestpath(w, vec);
        for(int i=0; i<vec.size(); i++){
            cout<<vec[i].v()<<"->";
            if(i == vec.size()-1)
                cout<<vec[i].w()<<endl;
        }
    }
};


#endif /* Dijkstra_h */
