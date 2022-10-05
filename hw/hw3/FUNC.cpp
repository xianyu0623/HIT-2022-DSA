//
// Created by PC on 2022/10/5.
//
#include "TREE.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
node* new_node(int num){
    node* nn = (node*)malloc(sizeof(node));
    nn -> data = num;
    nn -> left = nullptr;
    nn -> right = nullptr;
}
Tree add_data(Tree T, int num){
    if(!T){
        return new_node(num);
    }
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
    pre_order(T -> left, order);
    order.push_back(T -> data);
    pre_order(T -> right, order);
}
void non_recursive_in_order(Tree T, vector<int> &order){
    stack<node*> stk;
    node* p = T;
    stk.push(p);
    while(!stk.empty()){

    }
}