//
//  search_tree.h
//  Tree
//  二分搜索树
//  Created by yufenZ on 2020/2/28.
//  Copyright © 2020年 yufenZ. All rights reserved.
//

#ifndef search_tree_h
#define search_tree_h
#include <iostream>
#include <queue>
using namespace std;

template <typename Key, typename Value>
class BST{
private:
    //节点
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;
        
        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
    };
    Node *root; //根节点
    int count;  //节点个数
    //插入节点
    Node* insert(Node *node, Key key, Value value){
        if(node == NULL){
            count ++;
            return new Node(key, value);
        }
        if(key == node->key)
            node->value = value;
        else if(key < node->key)
            node->left = insert(node->left, key, value);
        else
            node->right = insert(node->right, key, value);
        return node;
    }
    //判断节点递归函数
    bool contain(Node* node, Key key){
        if(node == NULL)
            return false;
        if(key == node->key)
            return true;
        else if(key < node->key)
            return contain(node->left, key);
        else
            return contain(node->right, key);
    }
    //查找节点的递归函数
    Value* search(Node* node, Key key){
        if(node == NULL)
            return NULL;
        if(key == node->key)
            return &(node->value);
        else if(key < node->key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }
    //前序遍历递归函数
    void preOrder(Node* node){
        if(node != NULL){
            cout<<node->key<<endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    //中序遍历递归函数
    void inOrder(Node* node){
        if(node!= NULL){
            inOrder(node->left);
            cout<<node->key<<endl;
            inOrder(node->right);
        }
    }
    //后序遍历递归函数
    void postOrder(Node* node){
        if(node != NULL){
            postOrder(node->left);
            postOrder(node->right);
            cout<<node->key<<endl;
        }
    }
    //利用递归编写析构函数
    void destroy(Node* node){
        if(node != NULL){
            destroy(node->left);
            destroy(node->right);
            delete node;
            count --;
        }
    }
    //返回以node为根的二分搜索树的最小键值所在节点
    Node* minimum(Node* node){
        if(node->left == NULL)
            return node;
        return minimum(node->left);
    }
    //返回以node为根的二分搜索树的最大键值所在节点
    Node* maximum(Node* node){
        if(node->right == NULL)
            return node;
        return maximum(node->right);
    }
    //删除最小节点,返回删除节点后的二分搜索树
    Node* removeMin(Node* node){
        if(node->left == NULL){
            Node* rightNode = node->right;
            delete node;
            count --;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }
    //删除最大节点，返回删除节点后的二分搜索树
    Node* removeMax(Node* node){
        if(node->right == NULL){
            Node* leftNode = node->left;
            delete node;
            count --;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
    }
    //删除键值为key的节点，返回删除节点后的二分搜索树
    Node* remove(Node* node, Key key){
        if(node == NULL)
            return NULL;
        if(key < node->key){
            node->left = remove(node->left, key);
            return node;
        }
        else if(key > node->key){
            node->right = remove(node->right, key);
            return node;
        }
        else{
            if(node->left == NULL){
                Node* rightNode = node->right;
                delete node;
                count --;
                return rightNode;
            }
            if(node->right == NULL){
                Node* leftNode = node->left;
                delete node;
                count --;
                return leftNode;
            }
            
            Node *successor = new Node(minimum(node->right));
            count ++;
            successor->right = removeMin(node->right);
            successor->left = node->left;
            delete node;
            count --;
            return successor;
        }
    }
public:
    //构造函数
    BST(){
        root = NULL;
        count = 0;
    }
    //析构函数
    ~BST(){
        destroy(root);
    }
    int size(){
        return count;
    }
    bool isEmpty(){
        return count == 0;
    }
    //插入节点函数
    void insert(Key key, Value value){
        root = insert(root, key, value);
    }
    //判断节点是否在树上
    bool contain(Key key){
        return contain(root, key);
    }
    //查找节点
    Value* search(Key key){
        return search(root, key);
    }
    //前序遍历
    void preOrder(){
        preOrder(root);
    }
    //中序遍历
    void inOrder(){
        inOrder(root);
    }
    //后序遍历
    void postOrder(){
        postOrder(root);
    }
    //层序遍历
    void levelOrder(){
        if(root == NULL)
            return;
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            Node *node = q.front();
            q.pop();
            cout<<node->key<<endl;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
    //寻找二叉树最小键值
    Key minimum(){
        assert(count!=0);
        Node* minNode = minimum(root);
        return minNode->key;
    }
    //寻找二叉树最大键值
    Key maximum(){
        assert(count!=0);
        Node* maxNode = maximum(root);
        return maxNode->key;
    }
    //删除最小值所在节点
    void removeMin(){
        if(root)
            root = removeMin(root);
    }
    //删除最大值所在节点
    void removeMax(){
        if(root)
            root = removeMax(root);
    }
    //删除键值为key的节点
    void remove(Key key){
        root = remove(root, key);
    }
};
#endif /* search_tree_h */
