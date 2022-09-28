#include <iostream>
#include "LINKLIST.h"

void init_linklist(Node* h);
void print(Node* h);
Node* add(Node* h);
int delete_e(Node *h, int x);
void sort_linklist(Node *h);
void delete_repeat(Node *h);
void reverse_link(Node* h);
void cy_move(Node *h, int dir);
void cy_mv_k(Node *h, int k, int dir);
Node* merge(Node* L1, Node* L2);
int main() {
    using namespace std;
    Node* h = new Node;
    init_linklist(h);
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
            init_linklist(h);
        }
        else if(op == 2){
            add(h);
            print(h);
        }
        else if(op == 3){
            int x;
            cout << "请输入要删除的元素：";
            cin >> x;
            cout<<"删除前：";
            print(h);
            if(delete_e(h, x)) {
                cout<<"删除后：";
                print(h);
            }
        }
        else if(op == 4){
            print(h);
        }
        else if(op == 5){
            cout<<"删除前：";
            print(h);
            delete_repeat(h);
            cout<<"删除后：";
            print(h);
        }
        else if(op == 6){
            cout << "翻转前：" ;
            print(h);
            reverse_link(h);
            cout << "翻转后：";
            print(h);
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
            cy_mv_k(h, k, dir);
            print(h);
        }
        else if(op == 8){
            Node* L1 = new Node;
            Node* L2 = new Node;
            init_linklist(L1);
            init_linklist(L2);
            cout<<"现在输入第一个顺序表元素"<<endl;
            add(L1);
            cout<<"现在输入第二个顺序表的元素"<<endl;
            add(L2);
            sort_linklist(L1);
            print(L1);
            sort_linklist(L2);
            print(L2);
            print(merge(L1, L2));
        }
        else{
            break;
        }
    }

    return 0;
}
