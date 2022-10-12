//
// Created by PC on 2022/10/12.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Huffman_Tree.h"
#include <algorithm>
#include <unordered_map>
#include <bitset>

using namespace std;
//实现小根堆
class MinHeap{
public:
    //储存的元素
    vector<Node*> heap;
    //类的函数
    MinHeap(vector<Node*> &nodes){
        for(int i = 0; i < nodes.size(); i++){
            heap.push_back(nodes[i]);
        }
        for(int i = heap.size() / 2 - 1; i >= 0; i--){
            MinHeapify(i);
        }
    }
    //插入节点,i是插入节点的位置
    void MinHeapify(int i){
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;
        if(l < heap.size() && heap[l]->weight < heap[i]->weight){
            smallest = l;
        }
        if(r < heap.size() && heap[r]->weight < heap[smallest]->weight){
            smallest = r;
        }
        if(smallest != i){
            swap(heap[i], heap[smallest]);
            MinHeapify(smallest);//递归调用
        }
    }
    //提取最小的节点并删除
    Node* ExtractMin(){
        Node* min = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        MinHeapify(0);
        return min;
    }

    void Insert(Node* node){
        heap.push_back(node);
        int i = heap.size() - 1;
        while(i > 0 && heap[(i - 1) / 2]->weight > heap[i]->weight){
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    bool Empty(){
        return heap.empty();
    }

};





void Get_frequency(int frequency[]){
    //读取文件
    ifstream infile;
    infile.open("C:/Users/PC/Desktop/things/datastructure/exp/Huffman/ihaveadream.txt");
    if(!infile.is_open()){
        cout<<"文件打开失败"<<endl;
        return;
    }
    //统计字符频率
    char ch;
    while(infile.get(ch)){
        frequency[ch]++;
    }
}
bool compare(Node* &a,Node* &b){
    return (a -> weight) < (b -> weight);
}

Tree merge_nodes(Tree a, Tree b){
    Tree res = nullptr;
    res=(Tree) malloc(sizeof(Node));
    if(!res) return nullptr;
    res -> weight = (a -> weight) + (b -> weight);
    res -> data = -1;
    res -> left = a;
    res -> right = b;
    return res;
}

Tree Construct_Huffman_Tree(int frequency[], vector<Node*> &nodes){
    //将nodes转换为小根堆

    for(int i = 0 ; i < 128 ; i++){
        if(frequency[i]){
            Node* nn = (Node*)malloc(sizeof(Node));
            nn -> data = i;
            nn -> weight = frequency[i];
            nn -> left = nullptr;
            nn -> right = nullptr;
            nodes.push_back(nn);
        }
    }
    MinHeap heap(nodes);
    while(!heap.Empty()){
        Tree a = heap.ExtractMin();
        Tree b = heap.ExtractMin();
        Tree c = merge_nodes(a, b);
        if (heap.Empty()) return c;
        heap.Insert(c);

    }
    return nodes[0];
}

void Huffman_code(Tree T,HASH2 &codes,string s){
    if(T -> data != -1) {
        codes.insert({T -> data, s});
        return;
    }
    Huffman_code(T -> left, codes, s + '0');
    Huffman_code(T -> right, codes, s + '1');
}
void Output_codes(HASH2 codes,string outpath, string inpath){
    //输出编码
    ofstream outfile;
    outfile.open(outpath,ios::binary);
    if(!outfile.is_open()){
        cout<<"文件打开失败"<<endl;
        return;
    }
    ifstream infile;
    infile.open(inpath);
    char ch;
    while(infile.get(ch)){
        outfile<<codes[ch];
    }
}

void Decode(Tree T, string outpath, string inpath){
    ofstream outfile;
    outfile.open(outpath);
    if(!outfile.is_open()){
        cout<<"文件打开失败"<<endl;
        return;
    }
    ifstream infile;
    infile.open(inpath);
    char temp;
    Tree p = T;
    while(infile.get(temp)){
        if(p -> data != -1){
            outfile << char(p -> data);
            p = T;
        }
        if(temp == '0'){
            p = p -> left;
        }
        if(temp == '1'){
            p = p -> right;
        }
    }
}