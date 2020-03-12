//
//  main.cpp
//  Graph_Basis
//
//  Created by yufenZ on 2020/3/2.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#include <iostream>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"
using namespace std;
////建立20个节点，100条边的图，并用邻接表和邻接矩阵分别表示
//int main(int argc, const char * argv[]) {
//    int N = 20, M = 100;
//
//    sparseGraph g1(N, false);
//    for(int i=0; i<M; i++){
//        int a = rand()%N;
//        int b = rand()%N;
//        g1.addEdge(a, b);
//    }
//    for(int v=0; v<N; v++){
//        cout<<v<<":";
//        sparseGraph::adjIterator adj(g1, v);
//        for(int w=adj.begin(); !adj.end(); w = adj.next())
//            cout<<w<<" ";
//        cout<<endl;
//    }
//
//    cout<<"-----------------------------"<<endl;
//
//    denseGraph g2(N, false);
//    for(int i=0; i<M; i++){
//        int a = rand()%N;
//        int b = rand()%N;
//        g2.addEdge(a, b);
//    }
//    for(int v=0; v<N; v++){
//        cout<<v<<":";
//        denseGraph::adjIterator adj(g2, v);
//        for(int w=adj.begin(); !adj.end(); w = adj.next())
//            cout<<w<<" ";
//        cout<<endl;
//    }
//    return 0;
//}
/*
//从文件中读取图的信息
//测试图的联通分量算法
int main(){
    //使用两种图的存储方式分别读取textG1.txt
    string filename = "/Users/yufenz/Desktop/C++/图解算法/Graph_Basis/Graph_Basis/textG1.txt";
    sparseGraph g1(13, false);
    readGraph<sparseGraph> readGraph1(g1, filename);
    component<sparseGraph> component1(g1);
    // cout<<"test G1 in Sparse Graph:"<<endl;
    // g1.show();
    cout<<"TestG1.txt, Using Sparse Graph, Component Count:"<<component1.count()<<endl;
    
    cout<<endl;
    
    denseGraph g2(13, false);
    readGraph<denseGraph> readGraph2(g2, filename);
    component<denseGraph> component2(g2);
    // cout<<"test G1 in Dense Graph: "<<endl;
    // g2.show();
    cout<<"TestG1.txt, Using Dense Graph, Component Count:"<<component2.count()<<endl;
    
    cout<<endl;
    
    //使用两种图的存储方式分别读取textG2.txt
    filename = "/Users/yufenz/Desktop/C++/图解算法/Graph_Basis/Graph_Basis/textG2.txt";
    sparseGraph g3(6, false);
    readGraph<sparseGraph> readGraph3(g3, filename);
    component<sparseGraph> component3(g3);
    cout<<"TestG2.txt, Using Sparse Graph, Component Count:"<<component3.count()<<endl;
    // cout<<"test G2 in Sparse Graph:"<<endl;
    // g3.show();
    
    cout<<endl;
    
    denseGraph g4(6, false);
    readGraph<denseGraph> readGraph4(g4, filename);
    component<denseGraph> component4(g4);
    cout<<"TextG2.txt, Using Dense Graph, Component Count:"<<component4.count()<<endl;
    // cout<<"test G2 in Dense Graph:"<<endl;
    // g4.show();
    return 0;
}
*/

//测试寻路算法和最短路径
int main(){
    string filename = "/Users/yufenz/Desktop/C++/图解算法/Graph_Basis/Graph_Basis/testG3.txt";
    sparseGraph g = sparseGraph(7, false);
    readGraph<sparseGraph> readGraph1(g, filename);
    g.show();
    cout<<endl;
    
    Path<sparseGraph> path1(g, 0);
    cout<<"Path from 0 to 6:"<<endl;
    path1.show(6);
    
    shortestPath<sparseGraph> bfs(g, 0);
    cout<<"BFS:";
    bfs.show(6);
    cout<<endl;
    return 0;
}
