#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll M = 1e9 + 7;
ll a, b; 
double f(double x){
    return 1.0 * (a/sqrt(1 + x)) + b*x;
}

double solve(ll l, ll h){
    while(h - l > 2){
        ll m1 = l + (h - l)/3;
        ll m2 = h - (h - l)/3;
        // cout << f(m1) << " " << f(m2) << endl;
        if(f(m1) < f(m2)) h = m2;
        else l = m1;
    }
    double best = l;
    for(ll x = l; x <= h; x++){
        if(f(x) < f(best)) best = x;
    }
    return f(best);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> a >> b;
    printf("%.6f", solve(0, pow(10, 12)));
}