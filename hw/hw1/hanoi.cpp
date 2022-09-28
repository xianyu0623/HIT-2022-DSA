#include "iostream"
using namespace std;

//汉诺塔问题,并统计移动次数
int count = 0;
void hanoi(int n, char a, char b, char c){
    cout << "hanoi(" << n << ", " << a << ", " << b << ", " << c << ")" << endl;
    if (n == 1){
        cout << a << "-->" << c << endl;
        count++;
    }
    else{
        hanoi(n - 1, a, c, b);
        cout << a << "-->" << c << endl;
        count++;
        hanoi(n - 1, b, a, c);
    }
}
int main(){
    int n;
    cout << "layers：";
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    cout << "count：" << count << endl;
    return 0;
}

