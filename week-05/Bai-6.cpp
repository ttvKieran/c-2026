#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll M = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    string s; cin >> s;
    string res = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] != '.') res += s[i];
    }
    cout << res;
}