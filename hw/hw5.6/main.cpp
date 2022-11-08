#include <iostream>
#include <algorithm>
typedef struct node{
    int data;
    node* left;
    node* right;
}Node;
class BST{
public:
    Node* root;
    BST(){
        this -> root = nullptr;
    }
    void insert(int n){
        if(root == nullptr){
            Node* n_node = new Node;
            n_node -> data = n;
            n_node -> left = nullptr;
            n_node -> right = nullptr;
            this -> root = n_node;
            return;
        }
        Node* p = this -> root;
        while(1){
            if(!p -> left && n < p -> data){
                Node* nnode = new Node;
                nnode -> data = n;
                nnode -> left = nullptr;
                nnode -> right = nullptr;
                p -> left = nnode;
                return;
            }
            else if(!p -> right && n >= p -> data){
                Node* nnode = new Node;
                nnode -> data = n;
                nnode -> left = nullptr;
                nnode -> right = nullptr;
                p -> right = nnode;
                return;
            }
            else if(p -> left && n < p -> data){
                p = p -> left;
                continue;
            }
            else if(p-> right && n >= p -> data){
                p = p -> right;
                continue;
            }
        }
    }
    int BST_find(int n, int cnt){
        using namespace std;
        Node* p = this -> root;
        while(p){
            if(n == p -> data){
            return cnt;
            }
            if(n < p -> data) {
                cnt++;
                p = p->left;
            }else{
                cnt++;
                p = p -> right;
            }
        }
        return cnt;
    }
    Node* BST_delete_in(Node* p,int n){
        using namespace std;
        if(!p) return p;
        if(n < p -> data){
            p -> left = BST_delete_in(p -> left, n);
            return p;
        }
        if(n > p -> data){
            p -> right = BST_delete_in(p -> right, n);
            return p;
        }
        // ///////
        if(!p -> left && !p -> right){
            delete p;
            return nullptr;
        }
        if(p -> left && !p -> right){
            Node* res = p -> left;
            //delete p;
            return res;
        }
        if(p -> right && !p -> left){
            Node* res = p -> right;
            //delete p;
            return res;
        }
        if(p -> left && p -> right){
            int m = Find_max(p -> left);
            p -> data = m;
            p -> left = BST_delete_in(p-> left,m);
            return p;
        }
    }
    int Find_max(Node* p){
        if(!p) return 0;
        if(!p->right) return p->data;
        return Find_max(p -> right);
    }
    void BST_delete(int n){
        this -> root = BST_delete_in(this->root, n);
    }
    void sort(Node* p){
        using namespace std;
        if(!p) return;
        sort(p -> left);
        cout << p -> data << ",";
        sort(p-> right);

    }
};
void data_init(int data_set[], int n){
    for(int i = 0; i < n ; i ++){
        data_set[i] = i*2;
    }
}

int my_find(int data_set[],int l, int r, int n,int cnt){
    using namespace std;
    if(l > r){
//        cout << "Not found!" <<endl;
        return cnt;
    }
    int mid = (l+r)>>1;
    if(data_set[mid] == n){
//        cout << "Fount it!"<<endl;
        return cnt;
    }
    if(data_set[mid] > n){

        return my_find(data_set, l, mid - 1, n, cnt + 1);
    }
    if(data_set[mid] < n){

        return my_find(data_set, mid + 1, r, n,cnt + 1);
    }
}
int main() {
    using namespace std;
    int data_set[1024];
    data_init(data_set, 1024);
    BST bst1 =BST();
    for(int i = 0 ; i < 1024; i++){
        bst1.insert(data_set[i]);
    }
    random_shuffle(data_set,data_set+1024 - 1);
    BST bst2 = BST();
    for(int i = 0 ; i < 1024 ; i++){
        bst2.insert(data_set[i]);
    }
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    int cnt4 = 0;
    int cnt5 = 0;
    int cnt6 = 0;
    sort(data_set, data_set + 1024);
    for(int i = 0; i < 1024 ; i++){
        cnt1 += bst1.BST_find(data_set[i], 1);
        cnt2 += bst2.BST_find(data_set[i], 1);
        cnt3 += bst1.BST_find(data_set[i]+1, 1);
        cnt4 += bst2.BST_find(data_set[i]+1, 1);
        cnt5 += my_find(data_set, 0, 1024 - 1, data_set[i], 1);
        cnt6 += my_find(data_set, 0, 1024 - 1, data_set[i]+1, 1);
    }
    cout << "BST1 find: " << cnt1/1024 << endl;
    cout << "BST2 find: " << cnt2/1024 << endl;
    cout << "BST1 not find: " << cnt3/1024 << endl;
    cout << "BST2 not find: " << cnt4/1024 << endl;
    cout << "my_find find: " << cnt5/1024 << endl;
    cout << "my_find not find: " << cnt6/1024 << endl;

    return 0;
}
