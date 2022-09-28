#include <iostream>
#include <string>
const int N = 1e4 + 10;
using namespace std;
int ne[N];
void construc_prefix_table(string s){
    int j = -1;
    ne[0] = -1;
    for(int i = 1 ; i < s.size() ; i++){
        while(j >= 0 && s[i] != s[j + 1]){
            j = ne[j];
        }
        if(s[i] == s[j + 1]){
            j++;
        }
        ne[i] = j;
    }
}
int match(string s, string p){
   int j = -1;
   for(int i = 0; i < p.size(); i++ ){
       while(j >= 0 && p[i] != s[j + 1]){
           j = ne[j];
       }
       if(p[i] == s[j+1]){
           j++;
       }
       if(j == s.size() - 1){
           return i - s.size() + 1;
       }
   }
   return -1;
}

int main() {
    string s = "aabaae";
    string p = "aabaafaabaaeff";
    construc_prefix_table(s);
    cout << match(s, p);
    return 0;
}
