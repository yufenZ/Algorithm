//
//  main.cpp
//  UnionFind
//
//  Created by yufenZ on 2020/3/1.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#include <iostream>
#include "UnionFindTestHelper.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n = 1000000;
    // UnionFindTestHelper::testUF1(n);
    UnionFindTestHelper::testUF2(n);
    UnionFindTestHelper::testUF3(n);
    UnionFindTestHelper::testUF4(n);
    UnionFindTestHelper::testUF5(n);
    return 0;
}
