#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll M = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    double Sx, Sy, Gx, Gy, res; cin >> Sx >> Sy >> Gx >> Gy;
    if(Sx < Gx){
        // x > Sx, x < Gx -> (x - Sx)Gy = Sy(Gx - x)
        res = (Sy*Gx + Sx*Gy) / (Gy + Sy);
        if(res >= Sx && res <= Gx){
            printf("%.6f", res);
        }
    } else if(Sx > Gx){
        // x > Gx, x < Sx -> (Sx - x)Gy = Sy(x - Gx)
        res = (-Sy*Gx - Sx*Gy) / (-Gy - Sy);
        if(res <= Sx && res >= Gx){
            printf("%.6f", res); 
        }
    }
}