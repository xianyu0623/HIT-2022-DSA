#include <iostream>
#include <cstring>
#include "ctime"
#define PII pair<int, int>
#include <vector>

const int N = 1005;
using namespace std;
int maze[N][N];//迷宫
int n, m;
bool st[N][N];//记录是否走过
vector<vector<PII> > paths;//存储所有路径
typedef struct {
    PII m_stk[N];
    int top;
}my_stack; //自定义栈

void intialize_stack(my_stack &s) {
    s.top = -1;
}

void push(my_stack &s, PII x) {
    s.top++;
    s.m_stk[s.top] = x;
}

PII pop(my_stack &s) {
    s.top--;
    return s.m_stk[s.top + 1];
}

bool if_stk_empyt(my_stack &s) {
    if (s.top == -1) {
        return true;
    } else {
        return false;
    }
}

int size_of_stk(my_stack &s) {
    return s.top + 1;
}

void maze_initial(){
    srand((unsigned)time(NULL));
    cout << "请输入迷宫的长m，宽n" << endl;
    cin >> m >> n;
    cout << "请输入选项 1.手动构建迷宫 2.自动构建迷宫" <<endl;
    int opt;
    cin >> opt;
    if (opt==1){
        for(int i = 1; i <= m ; i++){
            for(int j = 1 ; j <= n ; j ++){
                int num;
                cin >> num;
                maze[i][j] = num;
            }
        }
    }
    else{
        for(int i = 1; i <= m ; i++){
            for(int j = 1 ; j <= n ; j ++){
                if(i == 1 && j == 1){
                    maze[i][j] = 0;//起点
                    continue;
                }
                int num = rand() % 2;//随机生成0或1
                maze[i][j] = num;
            }
        }
        maze[m][n] = 0;//终点
    }

}

void print_maze(){
    cout << "迷宫" << endl;
    for(int i = 1 ; i <= m; i++){
        for(int j = 1 ; j <= n ; j ++){
            printf("%d    ", maze[i][j]);
        }
        puts("");
    }
}
int cnt;
//利用递归求解


my_stack way;
void recursive_search_path(int i, int j) {
    if (i == m && j == n) {
        cnt++;
        //将路径存入paths
        vector<PII> path;
        for (int k = 0; k <= way.top; k++) {
            path.push_back(way.m_stk[k]);
        }
        paths.push_back(path);
        return;
    }
    if (maze[i][j] == 0 && !st[i][j]) {
        st[i][j] = true;//标记为已经走过
        //向着八个方向延伸
        push(way, {i, j});
        recursive_search_path(i + 1, j);
        recursive_search_path(i - 1, j);
        recursive_search_path(i, j + 1);
        recursive_search_path(i, j - 1);
        recursive_search_path(i + 1, j + 1);
        recursive_search_path(i + 1, j - 1);
        recursive_search_path(i - 1, j + 1);
        recursive_search_path(i - 1, j - 1);
        //状态恢复
        pop(way);
        st[i][j] = false;
    }
    return;
}

void non_recursive_search_paths(){
    int i = 1, j = 1;
    my_stack work;
    intialize_stack(work);
    my_stack way;
    intialize_stack(way);
    push(work, {i, j});

    while (!if_stk_empyt(work)) {
        PII tmp = pop(work);
        i = tmp.first;
        j = tmp.second;
        if(i == m && j == n){
            cnt++;
            //将路径存入paths
            vector<PII> path;
            for(int k = 0 ; k <= way.top ; k ++){
                path.push_back(way.m_stk[k]);
            }
            paths.push_back(path);
            continue;
        }
        st[i][j] = true;
        push(way, {i, j});
        int num = size_of_stk(work);
        //探索八个方向
        if(maze[i - 1][j] == 0 && !st[i - 1][j]){
            push(work, {i - 1, j});
        }

        if(maze[i][j - 1] == 0 && !st[i][j - 1]){
            push(work, {i, j - 1});
        }

        if(maze[i + 1][j] == 0 && !st[i + 1][j]){
            push(work, {i + 1, j});
        }

        if(maze[i][j + 1] == 0 && !st[i][j + 1]){
            push(work, {i, j + 1});
        }
        if(maze[i - 1][j - 1] == 0 && !st[i - 1][j - 1]){
            push(work, {i - 1, j - 1});
        }
        if(maze[i - 1][j + 1] == 0 && !st[i - 1][j + 1]){
            push(work, {i - 1, j + 1});
        }
        if(maze[i + 1][j - 1] == 0 && !st[i + 1][j - 1]){
            push(work, {i + 1, j - 1});
        }
        if(maze[i + 1][j + 1] == 0 && !st[i + 1][j + 1]){
            push(work, {i + 1, j + 1});
        }
        if(num == size_of_stk(work)){
            st[i][j] = false;
            pop(way);
        }

    }
}

void print_path(){
    cout << "根据迷宫的构造特点，起点为2，按照递增顺序即为路径" << endl;
    if (cnt == 0){
        cout << "无解" << endl;
        return;
    }
    //寻找最短
    int min = 100000;
    int min_index = 0;
    //遍历paths,将对应位置替换2,3,4....
    for(int i = 0 ; i < cnt ; i ++){
        int num = 2;
        if(paths[i].size() < min){
            min = paths[i].size();
            min_index = i;
        }
        for(int j = 0 ; j < paths[i].size() ; j ++){
            int x = paths[i][j].first;
            int y = paths[i][j].second;
            maze[x][y] = num;
            num++;
        }
        maze[m][n] = num;
        print_maze();
        //恢复迷宫
        for(int i = 1 ; i <= m ; i ++){
            for(int j = 1 ; j <= n ; j ++){
                if(maze[i][j] != 1 && maze[i][j] != 0) maze[i][j] = 0;
            }
        }
        cout << endl;
    }
    //输出最短路径
    cout << "最短路径为" << endl;
    int num = 2;
    for(int j = 0 ; j < paths[min_index].size() ; j ++){
        int x = paths[min_index][j].first;
        int y = paths[min_index][j].second;
        maze[x][y] = num;
        num++;
    }
    maze[m][n] = num;
    print_maze();
}


int main() {
    memset(maze, -1, sizeof(maze));
    maze_initial();
    print_maze();
    cout << "请输入选项 1.递归求解(可以得到所有的路径） 2.非递归求解（只能得到一条路径）" <<endl;
    int opt;
    cin >> opt;
    if(opt == 1){
        intialize_stack(way);
        recursive_search_path(1, 1);
        cout <<"找到的路径总数为："<< cnt << endl;
        cout << "所有路径为：" << endl;
        print_path();
    }
    else{
        non_recursive_search_paths();
        cout <<"找到的路径总数为："<< cnt << endl;
        cout << "所有路径为：" << endl;
        print_path();
    }
    return 0;
}
