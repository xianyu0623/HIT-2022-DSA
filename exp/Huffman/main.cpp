#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include "Huffman_Tree.h"
#include "iostream"
using namespace std;
const int N = 128;
int frequency[N];

void Get_frequency(int frequency[]);
Tree Construct_Huffman_Tree(int frequency[], vector<Node*> &nodes);
void Huffman_code(Tree T,HASH2 &codes,string s);
void Output_codes(HASH2 codes,string outpath, string inpath);
void Decode(Tree T, string outpath, string inpath);
int main() {
    //开始计时
    clock_t start, finish;
    double totaltime;
    start = clock();
    HASH2 code;
    vector<Node*> nodes;
    Get_frequency(frequency);
    Tree T = Construct_Huffman_Tree(frequency, nodes);
    Huffman_code(T, code, "");
    Output_codes(code, "C:/Users/PC/Desktop/things/datastructure/exp/Huffman/code.txt", "C:/Users/PC/Desktop/things/datastructure/exp/Huffman/ihaveadream.txt");
    Decode(T, "C:/Users/PC/Desktop/things/datastructure/exp/Huffman/decode.txt", "C:/Users/PC/Desktop/things/datastructure/exp/Huffman/code.txt");
    finish = clock();
    totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "The run time is: " << totaltime << "s" << endl;
    return 0;
}
