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
    ll res = 0;
    for(int i = 0; i < n; i++){
        ll h1 = k * (k + 1) / 2;
        ll h2 = k * (k - 1) / 2;
        res = (res%M + ((c[i].second%M * h1%M)%M + (c[i].first%M * h2%M)%M)%M)%M;
    }
    cout << res;
}