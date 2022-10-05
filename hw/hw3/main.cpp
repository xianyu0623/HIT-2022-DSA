#include <iostream>
#include "TREE.h"
#include <vector>
#include "FUNC.h"
using namespace std;
int main() {
    Tree T = nullptr;
    for(int i = 0 ; i < 10 ; i++){
        T = add_data(T, rand() % 10 + 1);
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
    return 0;
}
//传入函数指针，实现不同的遍历方式
void traverse(Tree T, vector<int> &order, void (*func)(Tree, vector<int> &)){
    func(T, order);
    print_order(order);
    order.clear();
}