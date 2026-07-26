#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll a, b, k; cin >> a >> b >> k;
    int l = 0;
    while(k--){
        if(l == 0){
            if(a != 2 == 0){
                a--; a /= 2; b += a;
            } else{
                a /= 2; b += a;
            }
        } else{
            if(b != 2 == 0){
                b--; b /= 2; a += b;
            } else{
                b /= 2; a += b;
            }
        }
        l = 1 - l;
    }
    cout << a << " " << b;
}