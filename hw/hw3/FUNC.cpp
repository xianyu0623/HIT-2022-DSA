//
// Created by PC on 2022/10/5.
//
#include "TREE.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
node* new_node(int num){
    node* nn = (node*)malloc(sizeof(node));
    nn -> data = num;
    nn -> left = nullptr;
    nn -> right = nullptr;
}
void print_order(vector<int> &order){
    for(int i = 0 ; i < order.size(); i++){
        cout << order[i] << ',';
    }
    puts("");
}
Tree add_data(Tree T, int num){
    //如果树为空，直接创建根节点
    if(!T){
        return new_node(num);
    }
    //如果树不为空，找到合适的位置插入
    else if(!(T -> left && T -> right)){
        if(!T -> left){
            T -> left = new_node(num);
            return T;
        }
        if(!T -> right){
            T -> right = new_node(num);
            return T;
        }
    }
    //如果左右子树都不为空，递归调用,使用随机数是为了让树更加平衡
    else{
        int r;
        r = rand() % 2;
        if(r == 0){
           add_data(T -> left, num);
        }
        else{
            add_data(T -> right, num);
        }
        return T;
    }
}

void print_tree(Tree T, int depth){
    if(!T){
        return;
    }
    for(int i = 1 ; i <= depth ; i ++){
        cout << "*";
    }
    cout << T -> data << endl;
    print_tree(T -> left, depth + 1);
    print_tree(T -> right, depth + 1);
}

void pre_order(Tree T, vector<int> &order){
    if(!T){
        return;
    }
    order.push_back(T -> data);
    pre_order(T -> left, order);
    pre_order(T -> right, order);
}
void non_recursive_pre_order(Tree T, vector<int> &order){
    stack<node*> stk;
    node* p = T;
    stk.push(p);
    while(!stk.empty()){
        p = stk.top();
        stk.pop();
        order.push_back(p -> data);
        if(p -> right) stk.push(p -> right);
        if(p -> left) stk.push(p -> left);
    }
}
void in_order(Tree T, vector<int> &order){
    if(!T){
        return;
    }
    in_order(T -> left, order);
    order.push_back(T -> data);
    in_order(T -> right, order);
}
void non_recursive_in_order(Tree T, vector<int> &order){
    stack<node*> stk;
    node* p = T;
    while(p != nullptr||!stk.empty()){
        if(p != nullptr){
            stk.push(p);
            p = p -> left;
        }
        else{
            p = stk.top();
            stk.pop();
            order.push_back(p -> data);
            p = p -> right;
        }
    }
}
void post_order(Tree T, vector<int> &order){
    if(!T){
        return;
    }
    post_order(T -> left, order);
    post_order(T -> right, order);
    order.push_back(T -> data);
}
void non_recursive_post_order(Tree T, vector<int> &order){
    stack<node*> stk;
    node* p = T;
    stk.push(p);
    while(!stk.empty()){
        p = stk.top();
        stk.pop();
        order.push_back(p -> data);
        if(p -> left) stk.push(p -> left);
        if(p -> right) stk.push(p -> right);
    }
    reverse(order.begin(), order.end());
}