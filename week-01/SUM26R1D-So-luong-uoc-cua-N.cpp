#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll M = 1e9 + 7;
int main(){
    int n; cin >> n;
    int cnt[1005];
    for(int i = 0; i < 1005; i++) cnt[i] = 0;
    for(int i = 2; i <= n; i++){
        int x = i;
        for(int j = 2; j <= 1000; j++){
            while(x % j == 0){
                x /= j;
                cnt[j]++;
            }
        }
        if(x != 1) cnt[x]++;
    }
    ll res = 1;
    for(int i = 0; i < 1005; i++){
        if(cnt[i] != 0){
            res = ((res % M) * ((cnt[i] + 1) % M)) % M;
        }
    }
    cout << res;
}