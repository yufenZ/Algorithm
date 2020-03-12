//
//  main.cpp
//  Mininum-Tree
//
//  Created by yufenZ on 2020/3/3.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "LazyPrimMST.h"
#include "PrimMST.h"
#include "KruskalMST.h"
using namespace std;

/* 测试如何用两种图的表示方式表示有权图
int main(int argc, const char * argv[]) {
    
    string filename = "/Users/yufenz/Desktop/C++/图解算法/Mininum-Tree/Mininum-Tree/testG1.txt";
    int V = 8;
    cout<<fixed<<setprecision(2);
    denseGraph<double> g1 = denseGraph<double>(V, false);
    readGraph<denseGraph<double>, double> readGraph1(g1, filename);
    g1.show();
    cout<<endl;
    
    sparseGraph<double> g2 = sparseGraph<double>(V, false);
    readGraph<sparseGraph<double>, double> readGraph2(g2, filename);
    g2.show();
    return 0;
}
*/
// 测试生成最小树算法
int main(){
    string filename = "/Users/yufenz/Desktop/C++/图解算法/Mininum-Tree/Mininum-Tree/testG1.txt";
    int V = 8;
    sparseGraph<double> g = sparseGraph<double>(V, false);
    readGraph<sparseGraph<double>, double> readGraph1(g, filename);
    //测试Prim算法
    cout<<"Test Lazy Prim MST:"<<endl;
    LazyPrimMST<sparseGraph<double>, double>lazyPrimMST(g);
    vector<Edge<double>> mst = lazyPrimMST.mstEdge();
    for(int i=0; i<mst.size(); i++)
        cout<<mst[i]<<endl;
    cout<<"The MST weight is:"<<lazyPrimMST.result()<<endl;
    cout<<endl;
    
    //测试改进的Prim算法
    cout<<"Test Prim MST:"<<endl;
    PrimMST<sparseGraph<double>, double> primMST(g);
    mst = primMST.mstEdges();
    for(int i=0; i<mst.size(); i++)
        cout<<mst[i]<<endl;
    cout<<"The MST weight is:"<<primMST.result()<<endl;
    cout<<endl;
    
    //测试Kruskal算法
    cout<<"Test Kruskal MST:"<<endl;
    KruskalMST<sparseGraph<double>, double> kruskal(g);
    mst = kruskal.mstEdges();
    for(int i=0; i<mst.size(); i++)
        cout<<mst[i]<<endl;
    cout<<"The MST Weight is:"<<kruskal.result()<<endl;
    cout<<endl;
    return 0;
}
