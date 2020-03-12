//
//  BellmanFord.h
//  ShortestPath
//
//  Created by yufenZ on 2020/3/4.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef BellmanFord_h
#define BellmanFord_h

#include <stack>
#include <vector>
#include <cassert>
#include "Edge.h"

template <typename Graph, typename Weight>
class BellmanFord{
private:
    Graph &G;
    int s; //起始点
    Weight* distTo; // distTo[i]存储从起始点s到i的最短路径长度
    vector<Edge<Weight>*> from; // from[i]记录最短路径中，到达i点的边
    bool hasNegativeCycle; // 标记是否有负权环
    
    bool detectNegativeCycle(){
        for(int i=0; i<G.V(); i++){
            typename Graph::adjIterator adj(G, i);
            for(Edge<Weight>* e=adj.begin(); !adj.end(); e=adj.next()){
                if(from[e->v()] && distTo[e->v()] + e->wt() < distTo[e->w()])
                    return true;
            }
        }
        return false;
    }
public:
    BellmanFord(Graph &graph, int s):G(graph){
        this->s = s;
        distTo = new Weight[G.V()];
        for(int i=0; i<G.V(); i++)
            from.push_back(NULL);
        
        //标记初始点s可达且距离为0
        distTo[s] = Weight();
        from[s] = new Edge<Weight>(s, s, Weight());
        //Bellman-Ford
        //进行V-1次循环，每一次循环求出从起始点到其余所有点，最多使用pass步可到达最短距离
        for(int pass=1; pass<G.V(); pass++){
            //每一次循环对所有的边进行一遍松弛操作
            //遍历所有的边
            for(int i=0; i<G.V(); i++){
                //使用邻边迭代器遍历一个点的所有边
                typename Graph::adjIterator adj(G, i);
                for(Edge<Weight> *e=adj.begin(); !adj.end(); e=adj.next()){
                    //对于每一个边首先判断e->v()可达
                    //之后看如果e->w()以前没有到达过，我们可以更新distTo[e->w()]
                    //或者e->w()以前到达过，但是通过这个e我们可以获得一个更短的路径
                    if(from[e->v()] && (!from[e->w()] || distTo[e->v()] + e->wt() < distTo[e->w()])){
                        distTo[e->w()] = distTo[e->v()] + e->wt();
                        from[e->w()] = e;
                    }
                }
            }
        }
        hasNegativeCycle = detectNegativeCycle();
    }
    //析构函数
    ~BellmanFord(){
        delete [] distTo;
        delete from[s];
    }
    //返回途中是否有负权环
    bool negativeCycle(){
        return hasNegativeCycle;
    }
    //返回从s到w点点最短路径的长度
    Weight shortestPathTo(int w){
        assert(w>=0 && w<G.V());
        assert(!hasNegativeCycle);
        assert(hasPathTo(w));
        return distTo[w];
    }
    //判断从s到w点是否联通
    bool hasPathTo(int w){
        assert(w>=0 && w<G.V());
        return from[w] != NULL;
    }
    //寻找从s到w点的最短路径，将路径存放在vec中
    void shortestPath(int w, vector<Edge<Weight>> &vec){
        assert(w>=0 && w<G.V());
        assert(!hasNegativeCycle);
        assert(hasPathTo(w));
        //通过from数组逆向查找从s到w的路径，存放在栈中
        stack<Edge<Weight>*> s;
        Edge<Weight> *e = from[w];
        while(e->v() != this->s){
            s.push(e);
            e = from[e->v()];
        }
        s.push(e);
        
        //从栈中依次取出元素，并存放在vec中
        while(!s.empty()){
            e = s.top();
            vec.push_back(*e);
            s.pop();
        }
    }
    //打印从s到w的路径
    void showPath(int w){
        assert(w>=0 && w<G.V());
        assert(!hasNegativeCycle);
        assert(hasPathTo(w));
        
        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        for(int i=0; i<vec.size(); i++){
            cout<<vec[i].v()<<"->";
            if(i == vec.size()-1)
                cout<<vec[i].w()<<endl;
        }
    }
};


#endif /* BellmanFord_h */
