#include <bits/stdc++.h>
using namespace std;

bool check(string s, int k){
    int A = 0;
    for(int i = 0; i < s.length(); i++){
        int d = s[i] - '0';
        A = (A * 10 + d) % k; 
    }
    if(A == 0) return true;
    else return false;
}

string result(string s){
    if(check(s, 13) && check(s, 7)) return "Both";
    else if(check(s, 13)) return "Div 13";
    else if(check(s, 7)) return "Div 7";
    return "None";
}

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        cout << result(s) << endl;
    }
}