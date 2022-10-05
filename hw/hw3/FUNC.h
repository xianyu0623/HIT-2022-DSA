//
// Created by PC on 2022/10/5.
//

#ifndef HW3_FUNC_H
#define HW3_FUNC_H
#include "TREE.h"
#include <vector>
using namespace std;
node* new_node(int num);
Tree add_data(Tree T, int num);
void print_tree(Tree T, int depth);
void pre_order(Tree T, vector<int> &order);
void non_recursive_pre_order(Tree T, vector<int> &order);
void in_order(Tree T, vector<int> &order);
void non_recursive_in_order(Tree T, vector<int> &order);
void post_order(Tree T, vector<int> &order);
void non_recursive_post_order(Tree T, vector<int> &order);
void print_order(vector<int> &order);
//传入函数指针，实现不同的遍历方式
void traverse(Tree T, vector<int> &order, void (*func)(Tree, vector<int> &));
#endif //HW3_FUNC_H
