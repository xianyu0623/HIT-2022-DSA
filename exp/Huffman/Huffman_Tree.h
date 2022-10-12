//
// Created by PC on 2022/10/12.
//

#ifndef HUFFMAN_HUFFMAN_TREE_H
#define HUFFMAN_HUFFMAN_TREE_H

typedef struct node{
    int data;//储存字符
    int weight;//储存权重
    node* left;
    node* right;
}Node;
typedef node* Tree;
#define HASH2 unordered_map<char, string>

#endif //HUFFMAN_HUFFMAN_TREE_H
