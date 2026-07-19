#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll M = 1e9 + 7;

int main(){
    ll n, m; cin >> n >> m;
    ll cnt[100005], f[n + 5];
    for(ll i = 0; i <= n; i++){
        cnt[i] = 0; f[i] = 0;
    } 
    for(ll i = 0; i < m; i++){
        ll x; cin >> x;
        cnt[x] = -1;
    }
    for(ll i = 1; i <= n; i++){
        if(cnt[i] == -1) f[i] = 0;
        else{
            if(i == 1) f[i] = 1;
            else if(i == 2) f[i] = f[i - 1] + 1;
            else{
                if(i - 1 > 0) f[i] = (f[i]%M + f[i - 1]%M) % M;
                if(i - 2 > 0) f[i] = (f[i]%M + f[i - 2]%M) % M;
            }
        }
    }
    // for(int i = 1; i <= n; i++) cout << f[i] << " ";
    cout << f[n];
}