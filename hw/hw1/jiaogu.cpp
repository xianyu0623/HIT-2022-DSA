#include "iostream"
#include "vector"
using namespace std;
//角谷猜想，并找出最长序列
vector<vector<int>> sequence;
vector<int> tmp;
void jiaogu(int n){
    tmp.push_back(n);
    if (n == 1){
        sequence.push_back(tmp);
        tmp.clear();
    }
    else{
        if (n % 2 == 0){
            jiaogu(n / 2);

        }
        else{
            jiaogu(3 * n + 1);
        }
    }
}
int main(){
    int n;
    for(int i = 2  ; i <= 100 ; i++){
        jiaogu(i);
    }
    //输出sequence中最长的序列
    int max = 0;
    int index = 0;
    for(int i = 0 ; i < sequence.size() ; i++){
        if(sequence[i].size() > max){
            max = sequence[i].size();
            index = i;
        }
    }
    cout << "max sequence: ";
    for(int i = 0 ; i < sequence[index].size() ; i++){
        cout << sequence[index][i] << " ";
    }
    cout << endl;
    return 0;
}
