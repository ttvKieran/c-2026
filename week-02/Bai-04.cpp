#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1){ cout << a[0]; return 0;}
    ll S = 0, mn = LLONG_MAX;
    bool hasPos = false, hasNeg = false, hasZero = false;
    for(ll x : a){
        S += llabs(x);
        mn = min(mn, llabs(x));
        if(x > 0) hasPos = true;
        else if(x < 0) hasNeg = true;
        else hasZero = true;
    }
    ll ans;
    if (hasZero || (hasPos && hasNeg)) ans = S;
    else ans = S - 2 * mn;
    cout << ans;
}