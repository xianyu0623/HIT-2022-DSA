#include <iostream>
#include <algorithm>
#include "Define_SeqList.h"
using namespace std;
void init_seqlist(seqlist *L);
void print(seqlist *L);
int add(seqlist *L, int x);
void addELM(seqlist *L);
int delete_e(seqlist *L, int x);
void sort_seqlist(seqlist *L);
void delete_repeat(seqlist* L);
void reverse_seq(seqlist *L);
void cy_move(seqlist *L, int dir);
void cy_mv_k(seqlist *L, int k, int dir);
seqlist* merge(seqlist* L1, seqlist* L2);
int main() {
    seqlist *L = new seqlist;
    while(1) {
        int op;
        cout << "*****主页*****" << endl;
        cout << "1.初始化顺序表" << endl;
        cout << "2.添加元素" << endl;
        cout << "3.删除元素" << endl;
        cout << "4.打印顺序表" << endl;
        cout << "5.删除重复元素" << endl;
        cout << "6.翻转线性表" << endl;
        cout << "7.循环移动k位" << endl;
        cout << "8.合并两个已经排好序的线性表" << endl;
        cout << "其他任意键--退出" << endl;
        cout << "*********" << endl;
        cin >> op;
        if(op == 1){
            init_seqlist(L);
        }
        else if(op == 2){
            addELM(L);
            print(L);
        }
        else if(op == 3){
            int x;
            cout << "请输入要删除的元素：";
            cin >> x;
            if(delete_e(L, x)) print(L);

        }
        else if(op == 4){
            print(L);
        }
        else if(op == 5){
            delete_repeat(L);
            print(L);
        }
        else if(op == 6){
            reverse_seq(L);
            print(L);
        }
        else if(op == 7){
            cout << "请输入移动位数" << endl;
            int k;
            cin >> k;
            int dir = -1;
            while(dir != 0 && dir != 1){
                cout << "请输入移动方向 0---左    1---右"<<endl;
                cin >> dir;
            }
            cy_mv_k(L, k, dir);
            print(L);
        }
        else if(op == 8){
            seqlist* L1 = new seqlist;
            seqlist* L2 = new seqlist;
            init_seqlist(L1);
            init_seqlist(L2);
            cout<<"现在输入第一个顺序表元素"<<endl;
            addELM(L1);
            cout<<"现在输入第二个顺序表的元素"<<endl;
            addELM(L2);
            sort_seqlist(L1);
            print(L1);
            sort_seqlist(L2);
            print(L2);
            print(merge(L1, L2));
        }
        else{
            break;
        }
    }

    return 0;
}

