//
//  ReadGraph.h
//  ShortestPath
//
//  Created by yufenZ on 2020/3/4.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef ReadGraph_h
#define ReadGraph_h

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>
using namespace std;

template <typename Graph, typename Weight>
class readGraph{
public:
    readGraph(Graph &graph, const string &filename){
        ifstream file(filename);
        string line;
        int V, E;
        assert(file.is_open());
        
        //从第一行读取图的节点个数和边的个数
        assert(getline(file, line));
        stringstream ss(line);
        ss>>V>>E;
        assert(V == graph.V());
        //读取每一条边的信息
        for(int i=0; i<E; i++){
            assert(getline(file, line));
            stringstream ss(line);
            int a,b;
            Weight w;
            ss>>a>>b>>w;
            assert(a>=0 && a<V);
            assert(b>=0 && b<V);
            graph.addEdge(a, b, w);
        }
    }
};

#endif /* ReadGraph_h */
