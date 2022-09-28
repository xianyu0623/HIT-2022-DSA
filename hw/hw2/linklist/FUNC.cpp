//
// Created by PC on 2022/9/18.
//
#include "iostream"
#include "LINKLIST.h"
#include "cstring"
#include "vector"
#include "algorithm"
#include "stack"
using namespace std;
void init_linklist(Node* h){
    h -> val = 0;
    h -> next = NULL;
}

void print(Node* h){
    Node* p = h -> next;
    while(p){
        cout << p -> val << ' ';
        p = p -> next;
    }
    puts("");
}

void addELM(Node* h, int x){
    Node* p = h -> next;
    Node* lp = h;
    while(p){
        lp = p;
        p = p -> next;
    }
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp -> next = NULL;
    tmp -> val = x;
    lp -> next = tmp;
}

void add(Node* h){
    int num;
    srand(1);
    cout << "请输入要添加元素的个数" << endl;
    cin >> num;
    cout<<"1.随机生成   2.手动输入"<<endl;
    int choice;
    cin >> choice;
    if(choice == 1){
        for (int i = 0; i < num; i++) {
            int x;
            x = rand() % 100 + 12;

            addELM(h, x);
        }
    }
    else{
        cout << "请输入要添加的元素：";
        for (int i = 0; i < num; i++) {
            int x;
            cin >> x;
            addELM(h, x);
        }
    }
}

int delete_e(Node *h, int x){
    Node* p = h -> next;
    Node* lp = h;
    while(p && p -> val != x){
        lp = p;
        p = p -> next;
    }
    if(!p){
        cout << "元素不存在！"<< endl;
        return 0;
    }
    else{
        lp -> next = p -> next;
        free(p);
    }
}

void sort_linklist(Node *h){
    vector<int> itm;
    Node* p = h -> next;
    while(p){
        itm.push_back(p -> val);
        p = p -> next;
    }
    sort(itm.begin() , itm.end());
    Node* p2 = h -> next;
    while(p2){
        Node* tmp = p2;
        p2 = p2 -> next;
        free(tmp);
    }
    Node* l = h;
    int n = itm.size();
    for(int i = 0; i < n; i++){
        Node* tmp = (Node*) malloc(sizeof(Node));
        tmp -> next = NULL;
        tmp -> val = itm[i];
        l -> next = tmp;
        l = l -> next;
    }
}
void delete_repeat(Node *h){
    sort_linklist(h);
    Node* p = h -> next;
    int tmp = p -> val;
    Node *lp = p;
    p = p -> next;
    while(p){
        if(p -> val == tmp){
            lp -> next = p -> next;
            free(p);
            p = lp -> next;
            continue;
        }
        tmp = p->val;
        lp = p;
        p = p -> next;
    }
}
void reverse_link(Node* h){
    stack<int> stk;
    Node* p = h -> next;
    while(p){
        stk.push(p -> val);
        p = p -> next;
    }
    Node* p2 = h -> next;
    while(p2){
        Node* tmp = p2;
        p2 = p2 -> next;
        free(tmp);
    }
    Node* l = h;
    while(!stk.empty()){
        Node* tmp = (Node*) malloc(sizeof(Node));
        tmp -> next = NULL;
        int num = stk.top();
        stk.pop();
        tmp -> val = num;
        l -> next = tmp;
        l = l -> next;
    }
}
void cy_move(Node *h, int dir){
    Node* p = h -> next;

    if(dir == 0){
        Node* tmp = p;
        while(p -> next){
            p = p -> next;
        }
        p -> next = tmp;
        h -> next = h -> next -> next;
        tmp -> next = NULL;

    }
    //将链表循环右移一位
    else{
        Node* lp = p;
        while(p -> next){
            lp = p;
            p = p -> next;
        }
        lp -> next = NULL;
        p -> next = h -> next;
        h -> next = p;
    }

}
void cy_mv_k(Node *h, int k, int dir){
    while(k--){
        cy_move(h, dir);
    }
}

Node* merge(Node* L1, Node* L2){
    Node* h = (Node*)malloc(sizeof(Node));
    init_linklist(h);
    Node* p1 = L1 -> next;
    Node* p2 = L2 -> next;
    while(p1 && p2){
        if(p1 -> val < p2 -> val){
            addELM(h, p1 -> val);
            p1 = p1 -> next;
        }
        else{
            addELM(h, p2 -> val);
            p2 = p2 -> next;
        }
    }
    while(p1){
        addELM(h, p1 -> val);
        p1 = p1 -> next;
    }
    while(p2){
        addELM(h, p2 -> val);
        p2 = p2 -> next;
    }
    return h;
}