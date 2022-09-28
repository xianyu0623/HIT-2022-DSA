//
// Created by PC on 2022/9/16.
//
#include "Define_SeqList.h"
#include "iostream"
#include "algorithm"
using namespace std;
//初始化顺序表
void init_seqlist(seqlist *L) {
    L->len = 0;
}

//打印顺序表
void print(seqlist *L) {
    if(L == NULL) {
        cout << "Error!" << endl;
        return;
    }
    for(int i = 0; i < L->len; i++) {
        cout << L->data[i] << " ";
    }
    cout << endl;
}

//添加元素
int add(seqlist *L, int x) {
    if(L == NULL) {
        cout<<"Error!"<<endl;
        return 0;
    }
    if(L->len == N) {
        cout << "Full!" << endl;
        return 0;
    }
    else{
        L->data[L->len] = x;
        L->len++;
        return 1;
    }
}
void addELM(seqlist *L){
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

            add(L, x);
        }
    }
    else{
        cout << "请输入要添加的元素：";
        for (int i = 0; i < num; i++) {
            int x;
            cin >> x;
            add(L, x);
        }
    }
}
//删除给定元素
int delete_e(seqlist *L, int x){
    if(L == NULL){
        cout << "Error!" << endl;
        return 0;
    }
    int idx = -1;
    for(int i = 0; i < L -> len; i++){
        if(L -> data[i] == x) {
            idx = i;
            break;
        }
    }
    if(idx == -1){
        cout << "Not found!" <<endl;
        return 0;
    }
    for(int k = idx; k < L -> len - 1; k++){
        L -> data[k] = L -> data[k+1];
    }
    L -> data[--(L -> len)] = 0;
    return 1;
}

//排序
void sort_seqlist(seqlist *L){
    sort(L -> data, L -> data + L ->len);
}

//对已排好序的列表删除重复元素
void delete_repeat(seqlist* L){
    sort_seqlist(L);
    int tmp = -10000;
    int i = 0;
    while(i < L -> len){
        if(L -> data[i] == tmp){
            delete_e(L, L -> data[i]);
            continue;
        }
        tmp = L -> data[i++];
    }
}

//逆置顺序表
void reverse_seq(seqlist *L){
    int l = 0;
    int r = L -> len - 1;
    while(l < r){
        swap(L -> data[l], L -> data[r]);
        l++;
        r--;
    }
}

//循环左/右移动代码
void cy_move(seqlist *L, int dir){
    //左
    if(dir == 0){
        int tmp = L -> data[0];
        for(int i = 0; i < L -> len - 1; i++){
            L -> data[i] =  L -> data[i+1];
        }
        L -> data[L -> len - 1] = tmp;
    }
        //右
    else{
        int tmp = L -> data[L -> len - 1];
        for(int i = L -> len - 1; i > 0; i--){
            L -> data[i] = L -> data[i - 1];
        }
        L -> data[0] = tmp;
    }
}

//循环移动k位
void cy_mv_k(seqlist *L, int k, int dir){
    while(k--){
        cy_move(L, dir);
    }
}

seqlist* merge(seqlist* L1, seqlist* L2){
    seqlist* res = new seqlist;
    int p1 = 0;
    int p2 = 0;
    while(p1 < L1 ->len && p2 < L1 -> len){
        if(L1 -> data[p1] < L2 -> data[p2]){
            add(res, L1 -> data[p1++]);
        }
        else{
            add(res, L2 -> data[p2++]);
        }
    }
    while(p1 < L1 -> len){
        add(res, L1 -> data[p1++]);
    }
    while(p2 < L2 -> len){
        add(res, L2 -> data[p2++]);
    }
    return res;
}