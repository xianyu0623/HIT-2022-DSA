#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int num[N];
void bubble_sort(int num[N], int len){
    for(int i = 0 ; i < len - 1 ; i ++){
        for(int j = i + 1 ; j < len ; j++){
            if(num[i] > num[j]) swap(num[i], num[j]);
        }
    }
}

void select_sort(int num[N], int len){
    for(int i = 0 ; i < len - 1 ; i++){
        int min = i;
        for(int j = i + 1; j < len ; j++){
            if(num[j] < num[min]){
                min = j;
            }
        }
        swap(num[i], num[min]);
    }
}
void insert_sort(int num[N], int len){
    for(int i = 1; i < len; i++){
        int val = num[i];
        int j;
        for(j = i - 1; j >= 0 && val < num[j]; j--){
            num[j + 1] = num[j];
        }
        num[j + 1] = val;

    }
}
void bubble_sort_recursion(int num[N], int len){
    if(len == 1) return;
    for(int i = 0 ; i < len - 1 ; i ++){
        if(num[i] > num[i + 1]) swap(num[i], num[i + 1]);
    }
    bubble_sort_recursion(num, len - 1);
}
void select_sort_recursion(int num[N], int len){
    if(len == 1) return;
    int max = 0;
    for(int i = 1 ; i < len ; i++){
        if(num[i] > num[max]) max = i;
    }
    swap(num[max], num[len - 1]);
    select_sort_recursion(num, len - 1);
}
void insert_sort_recursion(int num[N], int len){
    if(len == 1) return;
    insert_sort_recursion(num, len - 1);
    int val = num[len - 1];
    int j;
    for(j = len - 2; j >= 0 && val < num[j]; j--){
        num[j + 1] = num[j];
    }
    num[j + 1] = val;
}
int main() {
    srand(1);
    int len;
    cout << "请输入数组长度" << endl;
    cin >> len;
    for(int i = 0 ; i < len ; i++){
        num[i] = rand() % 10000 + 1;
    }
    for(int i = 0 ; i < len ; i++){
        cout << num[i] << ' ';
    }
    puts("");
    //测试各种排序算法的时间
    clock_t start, end;
    start = clock();
    bubble_sort(num, len);
    //select_sort(num, len);
    //insert_sort(num, len);
    //bubble_sort_recursion(num, len);
    //select_sort_recursion(num, len);
    //insert_sort_recursion(num, len);
    end = clock();
    for(int i = 0 ; i < len ; i++){
        cout << num[i] << "  ";
    }
    puts("");
    cout << "排序时间为" << (double)(end - start)/CLOCKS_PER_SEC <<"s"<<endl;
    return 0;
}
