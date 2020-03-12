//
//  UnionFindTestHelper.h
//  UnionFind
//
//  Created by yufenZ on 2020/3/1.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef UnionFindTestHelper_h
#define UnionFindTestHelper_h

#include <iostream>
#include <ctime>
#include "Union_Find.h"
#include "Union_Find2.h"
#include "Union_Find3.h"
#include "Union_Find4.h"
#include "Union_Find5.h"
using namespace std;

namespace UnionFindTestHelper {
   //测试第一个版本的函数
    void testUF1(int n){
        UF1::unionFind uf = UF1::unionFind(n);
        clock_t startTime = clock();
        
        for(int i=0; i<n; i++){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        
        for (int i=0; i<n; i++){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        clock_t endTime = clock();
        cout<<"UF1, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }
    //测试第二个版本的函数
    void testUF2(int n){
        UF2::unionFind uf = UF2::unionFind(n);
        clock_t startTime = clock();
        
        for(int i=0; i<n; i++){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        
        for (int i=0; i<n; i++){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        clock_t endTime = clock();
        cout<<"UF2, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }
    
    //测试第三个版本的函数
    void testUF3(int n){
        UF3::unionFind uf = UF3::unionFind(n);
        clock_t startTime = clock();
        
        for(int i=0; i<n; i++){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        
        for (int i=0; i<n; i++){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        clock_t endTime = clock();
        cout<<"UF3, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }
    
    //测试第四个版本的函数
    void testUF4(int n){
        UF4::unionFind uf = UF4::unionFind(n);
        clock_t startTime = clock();
        
        for(int i=0; i<n; i++){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        
        for (int i=0; i<n; i++){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        clock_t endTime = clock();
        cout<<"UF4, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }
    //测试第四个版本的函数
    void testUF5(int n){
        UF5::unionFind uf = UF5::unionFind(n);
        clock_t startTime = clock();
        
        for(int i=0; i<n; i++){
            int a = rand()%n;
            int b = rand()%n;
            uf.unionElements(a,b);
        }
        
        for (int i=0; i<n; i++){
            int a = rand()%n;
            int b = rand()%n;
            uf.isConnected(a,b);
        }
        clock_t endTime = clock();
        cout<<"UF5, "<<2*n<<" ops, "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }
    
}

#endif /* UnionFindTestHelper_h */
