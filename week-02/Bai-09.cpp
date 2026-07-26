#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(string s, ll b){
    ll cnt = 0;
    for(int i = 0; i < s.size()/2; i++){
        if(s[i] != s[s.size() - i - 1]){
            cnt += b;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    ll res = LLONG_MAX;
    for(int i = 0; i < n; i++){
        string tmp = s.substr(i, n) + s.substr(0, i);
        ll ans = solve(tmp, b);
        res = min(res, ans + i * a);
    }
    cout << res;
}