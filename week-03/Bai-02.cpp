#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll k; cin >> k;
    ll res = 0;
    bool check = false;
    for(ll i = 1; i * i <= k; i++){
        if(check) break;
        for(ll j = i; j * i <= k; j++){
            if(i * j > k){
                check = true; break;
            }
            ll x = i * j;
            ll y = k / x;
            y -= j - 1;
            if(y > 0){
                if(i == j){
                    res += (1 + 3*(y - 1));
                } else{
                    res += (3 + 6*(y - 1));
                }
            }
        }
    }
    cout << res;
}