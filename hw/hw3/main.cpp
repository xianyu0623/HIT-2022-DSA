#include <iostream>
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
int main() {
    Tree T = nullptr;
    for(int i = 0 ; i < 10 ; i++){
        T = add_data(T, rand() % 10 + 1);
    }
    print_tree(T, 0);
    vector<int> preoder;
    vector<int> nonpreoder;
    vector<int> inoder;
    vector<int> noninoder;
    pre_order(T, preoder);
    non_recursive_pre_order(T, nonpreoder);
    in_order(T, inoder);
    non_recursive_in_order(T, noninoder);
    for(int i = 0 ; i < preoder.size(); i++){
        cout << preoder[i] << ',';
    }
    puts("");
    for(int i = 0 ; i < nonpreoder.size() ; i++){
        cout << nonpreoder[i] << ',';
    }
    puts("");
    for(int i = 0 ; i < inoder.size() ; i++){
        cout << inoder[i] << ',';
    }
    puts("");
    for(int i = 0 ; i < noninoder.size() ; i++){
        cout << noninoder[i] << ',';
    }
    return 0;
}
