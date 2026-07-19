#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long pow_long(long long x, long long y){
    ll res = x;
    for(ll i = 2; i <= y; i++){
        res *= x;
    }
    return res;
}

int main(){
    long long n; cin >> n;
    int A = -1, B = -1;

    for(int i = 1; i <= 50; i++){
        ll p3 = pow_long(3, i);
        if(p3 >= n) break;
        for(int j = 1; j <= 40; j++){
            ll p5 = pow_long(5, j);
            if(p5 >= n) break;
            if(p3 + p5 == n){
                A = i; B = j;
                break;
            }
        }
    }

    if(A == -1) cout << "-1";
    else cout << A << " " << B;
}