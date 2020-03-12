//
//  main.cpp
//  ShortestPath
//
//  Created by yufenZ on 2020/3/4.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#include <iostream>
#include "Dijkstra.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "BellmanFord.h"
using namespace std;

int main(int argc, const char * argv[]) {
    //测试Dijkstra算法
    string filename = "/Users/yufenz/Desktop/C++/图解算法/ShortestPath/ShortestPath/testG1.txt";
    int V = 5;
    
    sparseGraph<int> g1 = sparseGraph<int>(V, true);
    readGraph<sparseGraph<int>, int> readGraph1(g1, filename);
    cout<<"Test Dijkstra:"<<endl<<endl;
    Dijkstra<sparseGraph<int>, int> dij(g1, 0);
    for(int i=0; i<V; i++){
        if(dij.hasPathTo(i)){
            cout<<"Shortest Path to "<<i<<":"<<dij.shortestPathTo(i)<<endl;
            dij.showPath(i);
        }
        else
            cout<<"No Path to"<<i<<endl;
        cout<<"--------------------"<<endl;
    }
    //测试Bellman—Ford算法
    filename = "/Users/yufenz/Desktop/C++/图解算法/ShortestPath/ShortestPath/testG2.txt";
    sparseGraph<int> g2 = sparseGraph<int>(V, true);
    readGraph<sparseGraph<int>, int> readGraph2(g2, filename);
    cout<<"Test Bellman-Ford:"<<endl<<endl;
    BellmanFord<sparseGraph<int>, int> blf(g2, 0);
    if(blf.negativeCycle())
        cout<<"The graph contain negative cycle!"<<endl;
    else{
        for(int i=0; i<V; i++){
            if(blf.hasPathTo(i)){
                cout<<"Shortest Path to "<<i<<":"<<blf.shortestPathTo(i)<<endl;
                blf.showPath(i);
            }
            else
                cout<<"No Path to"<<i<<endl;
            cout<<"----------------------"<<endl;
        }
    }
    return 0;
}
