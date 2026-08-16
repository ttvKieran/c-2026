#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll M = 1e9 + 7;
const int MAXN = 1000000;          
bool isComposite[MAXN + 1];         
vector<int> primes;                 

void sieve(){
    isComposite[0] = isComposite[1] = true; 
    for(int i = 2; i <= MAXN; i++){
        if(!isComposite[i]){
            primes.push_back(i);            
            for(ll j = (ll)i * i; j <= MAXN; j += i){
                isComposite[j] = true;    
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    sieve();
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll cnt = 0;
        for(int i = 0; i < primes.size(); i++){
            if(pow(primes[i], 8) <= n) cnt++;
            if(pow(primes[i], 2) < n){
                for(int j = i + 1; j < primes.size(); j++){
                    if(pow(primes[i], 2) * pow(primes[j], 2) <= n) cnt++;
                    else break;
                }
            } else break;
        }
        cout << cnt << endl;
    }
}