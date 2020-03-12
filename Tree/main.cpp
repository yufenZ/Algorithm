//
//  main.cpp
//  Tree
//  二分查找法
//  Created by yufenZ on 2020/2/28.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <queue>
#include "search_tree.h"
using namespace std;

int main(){
    
    //srand(time(NULL));
    //构建二叉树
    BST<int, int> bst = BST<int, int>();
    int N = 10, M = 100;
    for(int i=0; i<N; i++){
        int key = rand()%M;
        int value = key;
        cout<<key<<" ";
        bst.insert(key, value);
    }
    cout<<endl;
    
    cout<<"size:"<<bst.size()<<endl;
    
    cout<<"preOrder:"<<endl;
    bst.preOrder();
    cout<<endl;
    
    cout<<"inOrder:"<<endl;
    bst.inOrder();
    cout<<endl;
    
    cout<<"postOrder:"<<endl;
    bst.postOrder();
    cout<<endl;
    
    cout<<"levelOrder:"<<endl;
    bst.levelOrder();
    cout<<endl;
    
    return 0;
}


