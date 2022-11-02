#include <iostream>
#include "vector"
#include <cstring>
#define DATA int
const int N = 100;
using namespace std;
typedef struct node{
    DATA elm;
    int next[N];
    int next_num = 0;
}NODE;
bool st[N];
class graph_matrix{
public:
    int mtx[N][N];
    DATA data[N];//用于储存节点的数据
    int dim;

    graph_matrix(int n){
        memset(this -> mtx, -1, sizeof(this ->mtx));
        memset(this -> data, 0, sizeof(this -> data));
        this -> dim = n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                this -> mtx[i][j] = 0;
            }
        }
    }

    void add_node(int num, DATA elm){
        if(!is_legal(num)){
            printf_s("ERROR!\n");
            return;
        }
        this -> data[num] = elm;
    }


    bool is_legal(int num){
        return num > 0 && num <= this -> dim;
    }

    void change_node_val(int num, DATA elm){
        if(!is_legal(num)){
            printf_s("ERROR!\n");
            return;
        }
        data[num] = elm;
    }

    void add_edge(int x, int y){
        if(!(is_legal(x) && is_legal(y))){
            printf_s("ERROR!\n");
        }
        this -> mtx[x][y] ++;
    }

    DATA get_elm(int num){
        if(!is_legal(num)){
            printf_s("ERROR!\n");
            return -1;
        }
        return this -> data[num];
    }

    int in_degree(int num){
        int cnt = 0;
        for(int i = 1; i <= this->dim; i++){
            cnt += mtx[i][num];
        }
        return cnt;
    }

    int out_degree(int num){
        int cnt = 0;
        for(int i = 1; i <= this -> dim; i++){
            cnt += mtx[num][i];
        }
        return cnt;
    }
};
void mtx_dfs(graph_matrix &g, int x, int num){
    st[x] = true;
    printf_s("V%d:%d ->", x, g.get_elm(x));
    if(num == g.dim){
        printf_s(".\n");
        return;
    }
    for(int i = 1; i <= g.dim; i++){
        if(g.mtx[x][i] > 0 && !st[i]){
            mtx_dfs(g, i, num + 1);
            break;
        }
    }
    if(num < g.dim){
        for(int i = 1; i <= g.dim; i++){
            if(!st[i]){
                printf_s(".\n");
                mtx_dfs(g, i, num + 1);
            }
        }
    }
}
void mtx_bfs(graph_matrix &g, int x, int num){
    vector<int> q;
    q.push_back(x);
    st[x] = true;
    while(!q.empty()){
        int t = q[0];
        q.erase(q.begin());
        printf_s("V%d:%d ->", t, g.get_elm(t));
        for(int i = 1; i <= g.dim; i++){
            if(g.mtx[t][i] > 0 && !st[i]){
                q.push_back(i);
                num++;
                st[i] = true;
            }
        }
    }
    if(num == g.dim){
        printf_s(".\n");
        return;
    }
    for(int i = 1; i <= g.dim; i++){
        if(!st[i]){
            printf_s(".\n");
            mtx_bfs(g, i, num + 1);
        }
    }
}

class graph_link_table{
public:
    //利用领接表实现图
    NODE* head[N];
    int dim;
    graph_link_table(int n){
        this -> dim = n;
        for(int i = 1; i <= n; i++){
            this -> head[i] = nullptr;
        }
    }
    bool if_legal(int num){
        return (num > 0 && num <= this ->dim);
    }
    bool is_node(int num){
        if(!head[num]){
            printf_s("ERROR:The node has not been created!\n");
            return 0;
        }
        return 1;
    }
    void add_node(int num, DATA data){
        if(!if_legal(num)){
            printf_s("ERROR!\n");
        }
        if(!head[num]){
            head[num] = (NODE*) malloc(sizeof(NODE));
            head[num] -> elm = data;
            head[num] -> next_num = 0;
        }
        else{
            printf_s("ERROR:Node has existed!\n");
        }
    }
    void change_node_val(int num, DATA data){
        if(!if_legal(num)){
            printf_s("ERROR!\n");
            return;
        }
        if(!head[num]){
            printf_s("ERROR:The node has not been created!\n");
            return;
        }
        head[num] -> elm = data;
    }
    void add_edge(int x, int y){
        if(is_node(x) and is_node(y)){
            head[x] -> next[head[x] -> next_num++] = y;
        }
    }

    void delete_edge(int x, int y){
        if(is_node(x) and is_node(y)){
            if(head[x] -> next[y] > 0) head[x] -> next[y] --;
            else printf_s("ERROR:There is no edge between %d and %d!\n", x, y);
        }
    }

    int in_degree(int num){
        int cnt = 0;
        for(int i = 1; i <= this -> dim; i++){
            for(int j = 0; j < head[i] -> next_num; j++){
                if(head[i] -> next[j] == num) cnt ++;
            }
        }
        return cnt;
    }

    int out_degree(int num){
        return head[num] -> next_num;
    }

};
void link_dfs(graph_link_table &g, int x, int num){
    st[x] = true;
    printf_s("V%d:%d ->", x, g.head[x] -> elm);
    if(num == g.dim){
        printf_s(".\n");
        return;
    }
    for(int i = 0; i < g.head[x] -> next_num; i++){
        if(!st[g.head[x] -> next[i]]){
            link_dfs(g, g.head[x] -> next[i], num + 1);
            break;
        }
    }
    if(num < g.dim){
        for(int i = 1; i <= g.dim; i++){
            if(!st[i]){
                printf_s(".\n");
                link_dfs(g, i, num + 1);
            }
        }
    }
}
void link_bfs(graph_link_table &g, int x, int num){
    vector<int> q;
    q.push_back(x);
    st[x] = true;
    while(!q.empty()){
        int t = q[0];
        q.erase(q.begin());
        printf_s("V%d:%d ->", t, g.head[t] -> elm);
        for(int i = 0; i < g.head[t] -> next_num; i++){
            if(!st[g.head[t] -> next[i]]){
                q.push_back(g.head[t] -> next[i]);
                num++;
                st[g.head[t] -> next[i]] = true;
            }
        }
    }
    if(num == g.dim){
        printf_s(".\n");
        return;
    }
    for(int i = 1; i <= g.dim; i++){
        if(!st[i]){
            printf_s(".\n");
            link_bfs(g, i, num + 1);
        }
    }
}
//将图的邻接表转换为邻接矩阵
graph_matrix* link_to_matrix(graph_link_table* link){
    graph_matrix* matrix = new graph_matrix(link -> dim);
    for(int i = 1; i <= (link -> dim); i++){
        matrix -> add_node(i, link -> head[i] -> elm);
        for(int j = 1; j <= (link -> dim); j++){
            if(link -> head[i] -> next[j] != 0){
                matrix -> add_edge(i, j);
            }
        }
    }
    return matrix;
}
//将图的邻接矩阵转换为邻接表
graph_link_table* matrix_to_link(graph_matrix* matrix){
    graph_link_table* link = new graph_link_table(matrix -> dim);
    for(int i = 1; i <= matrix -> dim; i++){
        link -> add_node(i, matrix -> data[i]);
    }
    for(int i = 1; i <= matrix -> dim; i++){
        for(int j = 1; j <= matrix -> dim; j++){
            if(matrix -> mtx[i][j] != 0){
                link -> add_edge(i, j);
            }
        }
    }
    return link;
}

void set_false(bool st[]){
    for(int i = 1; i <= N; i++){
        st[i] = false;
    }
}
//将边保存到vector中
int main() {
    cout<<"input the number of nodes:";
    int nn;
    cin>>nn;
    graph_matrix G(nn);
    //**添加点和边**//
    //添加点
    for(int i = 1; i <= nn; i++){
        G.add_node(i, i);
    }
    //添加边
    int tmp;
    cout<<"input the number of edges:"<<endl;
    cin>>tmp;
    for(int i = 0; i < tmp; i++){
        int x, y;
        cin>>x>>y;
        G.add_edge(x, y);
    }
    graph_link_table* g = matrix_to_link(&G);
    set_false(st);
    printf_s("DFS:\n");
    mtx_dfs(G,1, 1);
    printf_s("\n");
    set_false(st);
    printf_s("BFS:\n");
    mtx_bfs(G, 1, 1);
    printf_s("\n");
    set_false(st);
    printf_s("DFS:\n");
    link_dfs(*g, 1, 1);
    printf_s("\n");
    set_false(st);
    printf_s("BFS:\n");
    link_bfs(*g, 1, 1);

    //每个节点的入度和出度
    for(int i = 1; i <= G.dim; i++){
        printf_s("V%d:%d -> in_degree:%d, out_degree:%d\n", i, G.data[i], G.in_degree(i), G.out_degree(i));
    }
    puts("");
    for(int i = 1; i <= g -> dim; i++){
        printf_s("V%d:%d -> in_degree:%d, out_degree:%d\n", i, g -> head[i] -> elm, g -> in_degree(i), g -> out_degree(i));
    }
    return 0;
}
