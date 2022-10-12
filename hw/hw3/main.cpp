#include <iostream>
#include "TREE.h"//里面包含了node的定义和Tree的定义
#include <vector>
#include "FUNC.h"//里面包含了函数的声明
using namespace std;
int main() {
    Tree T = nullptr;
    for(int i = 0 ; i < 10 ; i++){
        T = add_data(T, rand() % 20 + 1);
    }
    print_tree(T, 0);
    vector<int> order;
    cout<< "pre_order:" << endl;
    traverse(T, order, pre_order);
    traverse(T, order, non_recursive_pre_order);
    cout<< "in_order:" << endl;
    traverse(T, order, in_order);
    traverse(T, order, non_recursive_in_order);
    cout<< "post_order:" << endl;
    traverse(T, order, post_order);
    traverse(T, order, non_recursive_post_order);
    cout<< "layer_order:" << endl;
    traverse(T, order, layer_order);
    cout << "if_full_binary_tree:" << if_full_binary_tree(T) << endl;
    cout << "width_of_tree:" << width_of_tree(T) << endl;
    return 0;
}
//传入函数指针，实现不同的遍历方式
void traverse(Tree T, vector<int> &order, void (*func)(Tree, vector<int> &)){
    func(T, order);
    print_order(order);
    order.clear();
}