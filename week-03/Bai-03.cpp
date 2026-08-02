#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll M = 1e9 + 7;

ll power(ll base, ll exp){
    ll res = 1;
    base %= M;
    while(exp > 0){
        if(exp % 2 != 0) res = res * base % M;
        base = base * base % M;
        exp /= 2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll n; cin >> n;
    ll A = power(10, n) % M;
    ll B = power(9, n) % M;
    ll C = power(8, n) % M;
    cout <<  ((A - 2 * B + C) % M + M)%M;
}