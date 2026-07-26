#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll M = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll n, k; cin >> n >> k;
    ll a[n + 5];
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<pair<ll, ll>> c(n + 5);
    for(int i = 0; i < n; i++){
        c[i] = {0, 0};
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]) c[i].first++;
        }
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[i]) c[i].second++;
        }
    }
    // for(int i = 0; i < n; i++){
    //     cout << c[i].first << " " << c[i].second << endl;
    // }
    ll h1 = (k % (2*M)) * ((k + 1) % (2*M)) / 2 % M;  
    ll h2 = (k % (2*M)) * ((k - 1) % (2*M)) / 2 % M;
    h1 = (k * (k + 1) / 2) % M;
    h2 = (k * (k - 1) / 2) % M;
    ll res = 0;
    for(int i = 0; i < n; i++){
        res = (res + (c[i].second % M) * h1 % M) % M;
        res = (res + (c[i].first % M) * h2 % M) % M;
    }
    cout << res;
}