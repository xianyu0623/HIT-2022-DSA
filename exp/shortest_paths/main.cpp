#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct node{
    int v;
    int w;
    node(int _v, int _w):v(_v), w(_w){}//构造函数
};
const int N = 55;
bool st[N];
int dist[N];
class graph{
private:
    int dim;
    int MTX[N][N];
public:
    graph(int n){
        memset(this -> MTX, 0x3f, sizeof(this -> MTX));
        this -> dim = n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j)this -> MTX[i][j] = 0;
            }
        }
    }
    void add_node(int n_data){//添加节点
        if(this -> dim == 51){
            printf_s("Too many nodes!\n");
            return;
        }
        this -> dim++;
        this -> MTX[this -> dim][this -> dim] = n_data;
    }

    bool is_legal(int num){//判断节点是否存在
        return num > 0 && num <= this -> dim;
    }

    void add_edge(int x, int y, int weight){
        if(!(is_legal(x) && is_legal(y))){
            printf_s("ERROR!\n");
        }
        this -> MTX[x][y] = weight;
    }

    void Dijkstra(int src){
        int n = this -> dim;
        memset(dist, 0x3f, sizeof (dist));//初始化距离数组
        dist[src] = 0;//源点到源点的距离为0
        for (int i = 0; i < n - 1; i ++ ){
            int t = -1;//t为当前距离最小的点
            for (int j = 1; j <= n; j ++ )
                if (!st[j] && (t == -1 || dist[t] > dist[j]))//如果j点未被选中且距离更小
                    t = j;
            for (int j = 1; j <= n; j ++ )
                if(dist[t] + this -> MTX[t][j] < dist[j]){
                    dist[j] = dist[t] + this -> MTX[t][j];
                }

            st[t] = true;
        }
        for(int i = 1; i <= n ; i ++){
            if(dist[i] >= 0x3f3f3f/2){
                printf_s("V%d -> V%d: cannot reach!\n", src, i);//如果距离为无穷大，说明无法到达
                continue;
            }
            printf_s("V%d -> V%d: %d\n", src, i, dist[i]);//输出距离
        }
    }
    //floyd warshall输出最短路径长度和最短路径
    void Floyd_Warshall(){
        int n = this -> dim;
        int path[N][N];//通过path数组记录最短路径，path[i][j]表示i到j的最短路径上j的前一个节点
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                path[i][j] = j;//初始化path数组,每个节点的前一个节点都是自己
            }
        }
        //初始化
        for(int k = 1; k <= n; k++){//枚举中间节点
            for(int i = 1; i <= n; i++){//枚举起点
                for(int j = 1; j <= n; j++){//枚举终点
                    if(this -> MTX[i][j] > this -> MTX[i][k] + this -> MTX[k][j]){//和dijkstra算法不同的是，这里是比较两个点之间的距离和经过中间点的距离
                        this -> MTX[i][j] = this -> MTX[i][k] + this -> MTX[k][j];//更新最短路径长度
                        path[i][j] = path[i][k];//更新路径
                    }
                }
            }
        }
        while(1){
            cout<<"*******input your choice*******"<<endl;
            cout<<"***1. show all"<<endl;
            cout<<"***2. show the shortest path between v and c "<<endl;
            cout<<"***3. show the  shortest paths of the pair u and v"<<endl;
            cout<<"***4. exit"<<endl;
            int choice;
            cin>>choice;
            if(choice == 4){
                break;
            }
            if (choice == 1){
                for(int i = 1; i <= n; i++){//枚举起点
                    for(int j = 1; j <= n; j++){
                        if(this -> MTX[i][j] >= 0x3f3f3f/2){
                            printf_s("V%d -> V%d: cannot reach!\n", i, j);
                            continue;
                        }
                        printf_s("V%d -> V%d: %d\n", i, j, this -> MTX[i][j]);
                        //输出路径
                        int t = i;
                        while(t != j){//若t不等于j，说明还没到达终点
                            printf_s("V%d -> ", t);
                            t = path[t][j];
                        }
                        printf_s("V%d\n*********\n", j);

                    }
                }
            }
            if(choice == 2){
                int v, c;
                cout<<"input v and c"<<endl;
                cin>>v>>c;
                if(this -> MTX[v][c] >= 0x3f3f3f/2){
                    printf_s("V%d -> V%d: cannot reach!\n", v, c);
                    continue;
                }
                printf_s("V%d -> V%d: %d\n", v, c, this -> MTX[v][c]);
                cout<<"the shortest path is: "<<endl;
                cout<<v<<" ";
                while(v != c){
                    v = path[v][c];
                    cout<<v<<" ";
                }
                cout<<endl;
            }
            if(choice == 3){
                int u, v;
                cout<<"input u and v"<<endl;
                cin>>u>>v;
                int flag1 = 0,flag2 = 0;
                if(this -> MTX[u][v] >= 0x3f3f3f/2){
                    printf_s("V%d -> V%d: cannot reach!\n", u, v);
                    flag1 = 1;
                }
                if (this -> MTX[v][u] >= 0x3f3f3f/2){
                    printf_s("V%d -> V%d: cannot reach!\n", v, u);
                    flag2 = 1;
                }

                if(!flag1){
                    int tmp1 = u;
                    printf_s("V%d -> V%d: %d\n", u, v, this -> MTX[u][v]);
                    cout<<"the shortest path is: "<<endl;
                    cout<<u<<" ";
                    while(tmp1 != v){
                        tmp1 = path[tmp1][v];
                        cout<<tmp1<<" ";
                    }
                    cout<<endl;
                }
                if(!flag2){
                    int tmp2 = v;
                    printf_s("V%d -> V%d: %d\n", v, u, this -> MTX[v][u]);
                    cout<<"the shortest path is: "<<endl;
                    cout<<v<<" ";
                    while(tmp2 != u){
                        tmp2 = path[tmp2][u];
                        cout<<tmp2<<" ";
                    }
                    cout<<endl;
                }

            }

        }
    }

    //优先队列优化dijkstra算法
//    void Dijkstra_Priority_Queue(int s){
//        int n = this -> dim;
//        int dis[N];//记录起点到各个点的最短距离
//        int vis[N];//记录该点是否已经被访问过
//        memset(vis, 0, sizeof(vis));
//        for(int i = 1; i <= n; i++){
//            dis[i] = this -> MTX[s][i];
//        }
//        dis[s] = 0;
//        vis[s] = 1;
//        priority_queue<node> q;
//        q.push(node(s, 0));
//        while(!q.empty()){
//            node tmp = q.top();
//            q.pop();
//            int u = tmp.v;
//            if(vis[u]) continue;
//            vis[u] = 1;
//            for(int i = 1; i <= n; i++){
//                if(!vis[i] && dis[i] > dis[u] + this -> MTX[u][i]){
//                    dis[i] = dis[u] + this -> MTX[u][i];
//                    q.push(node(i, dis[i]));
//                }
//            }
//        }
//        for(int i = 1; i <= n; i++){
//            printf_s("V%d -> V%d: %d\n", s, i, dis[i]);
//        }
//    }

};
int main() {
    //顶点数为14
    graph g(12);
    //利用文件指针读取文件
    FILE *fp;
    //以只读方式打开文件
    fp = fopen("input.txt", "r");
    //判断文件是否打开
    if (fp == NULL) {
        printf("文件打开失败");
        return 0;
    }
    //逐行读入，每行的格式为：起点 终点 权值
    int a, b, c;
    while (fscanf(fp, "%d %d %d", &a, &b, &c) != EOF) {
        g.add_edge(a, b, c);
    }
    //Dijkstra算法
    int src;
    cout<<"input the source vertex"<<endl;
    cin>>src;
    printf_s("Dijkstra:\n");
    printf_s("source: V%d\n",src);
    g.Dijkstra(src);
    printf_s("-------------------------\n");
    //Floyd算法
    printf_s("Floyd:\n");
    g.Floyd_Warshall();
    return 0;
}
