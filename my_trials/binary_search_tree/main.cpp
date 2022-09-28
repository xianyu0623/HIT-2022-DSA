#include <iostream>
using namespace std;
typedef struct treenode{
    int num;
    struct treenode* left;
    struct treenode* right;
}node;

node* Make_empty(node* T){
    if(T !=NULL){
        Make_empty(T -> left);
        Make_empty(T -> right);
        free(T);
    }
    return NULL;
}

node* Find(node* T, int x) {
    if (T == NULL) {
        return NULL;
    }
    if (x < T->num) {
        Find(T->left, x);
    }
    else if (x > T->num) {
        Find(T->right, x);
    }
    else {
        return T;
    }
}

node* FindMin(node* T){
    if(T == NULL){
        return NULL;
    }
    else if(T -> left == NULL){
        return T;
    }
    else{
        return FindMin(T -> left);
    }
}

node* FindMax(node* T){
    if(T == NULL){
        return NULL;
    }
    else if(T -> right ==NULL){
        return T;
    }
    else{
        return FindMax(T -> right);
    }
}

node* Insert(int x, node* T){
    if(T == NULL){
        T = (node*)malloc(sizeof (node));
        T -> num = x;
        T ->left = T -> right = NULL;
        return T;
    }
    if(T == NULL){
        cout << "Out of space!" << endl;
        return NULL;
    }
    if(x < T -> num){
        T -> left = Insert(x, T -> left);
    }
    else if(x > T -> num){
        T -> right = Insert(x, T -> right);
    }
    else{
        return T;
    }
    return T;
}

node* Delete_node(node* T, int x){
    if(T == NULL){
        return NULL;
    }
    node *p = Find(T, x);
    if(p -> left == NULL && T -> right == NULL){
        free(p);
        return T;
    }
    else if(p -> left && p -> right){
        node* tmp = FindMin(p -> right);
        p -> num = tmp -> num;
        p = Delete_node(p -> right, x);
    }
    else{
        node* tmp;
        if(p -> left){
            p = p -> left;
        }
        else{
            p = p -> right;
        }
        free(tmp);
    }
}

void print(node* T ,int depth){
    if(T == NULL){
        return;
    }
    for(int i = 0; i < depth; i++){
        cout << "-";
    }
    cout << T -> num << endl;
    print(T -> right, depth + 1);
    print(T -> left, depth + 1);
}
int main() {
    //测试
    node* T = NULL;
    Make_empty(T);
    for(int i = 0 ; i < 10; i++){
        //随机生成10个数
        int x = rand() % 100;
        T = Insert(x, T);
    }
    print(T, 0);
    cout << "min:" << FindMin(T) -> num << endl;
    cout << "max:" << FindMax(T) -> num << endl;
    print(T, 0);


    return 0;
}
