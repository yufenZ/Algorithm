//
//  Edge.h
//  Mininum-Tree
//  边
//  Created by yufenZ on 2020/3/3.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef Edge_h
#define Edge_h

#include <iostream>
#include <cassert>
using namespace std;

template <typename Weight>
class Edge{
private:
    int a, b; // 边的两个顶点
    Weight weight; // 边的权重
public:
    //构造函数
    Edge(int a, int b, Weight weight){
        this->a = a;
        this->b = b;
        this->weight = weight;
    }
    Edge(){}
    // 析构函数
    ~Edge(){}
    int v(){return a;} // 返回起始点
    int w(){return b;} // 返回第二个顶点
    Weight wt(){return weight;} //返回边的权重
    //给定一个顶点，返回另一个顶点
    int other(int x){
        assert(x == a || x == b);
        return x==a?b:a;
    }
    //输出边的信息
    friend ostream& operator<<(ostream &os, const Edge &e){
        os<<e.a<<"-"<<e.b<<":"<<e.weight;
        return os;
    }
    //边的比较大小，是对边的权重进行比较
    bool operator<(Edge<Weight>& e){
        return weight<e.wt();
    }
    bool operator<=(Edge<Weight>& e){
        return weight<=e.wt();
    }
    bool operator>(Edge<Weight>& e){
        return weight>e.wt();
    }
    bool operator>=(Edge<Weight>& e){
        return weight>=e.wt();
    }
    bool operator==(Edge<Weight>& e){
        return weight==e.wt();
    }
};

#endif /* Edge_h */
