#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll n, k, s; cin >> n >> k >> s;
    long long dummy = (s == 1000000000) ? 1 : s + 1;
    for(long long i = 0; i < k; i++){
        cout << s << " ";
    }
    for(long long i = k; i < n; i++){
        cout << dummy << " ";
    }
}