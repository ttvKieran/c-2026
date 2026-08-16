#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll M = 1e9 + 7;
vector<bool> check(2005, false);

ll euclid(int x1, int y1, int x2, int y2){
    return ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

void solve(vector<vector<int>> v){
    queue<int> q; q.push(0);
    check[0] = true;
    vector<bool> used(2005, false); used[0] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int y : v[x]){
            if(!used[y]){
                q.push(y);
                check[y] = true; used[y] = true;
            } 
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll n, d; cin >> n >> d;
    vector<vector<int>> v(n);
    vector<pair<int, int>> e;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        e.push_back({x, y});
        for(int j = 0; j < i; j++){
            if(euclid(x, y, e[j].first, e[j].second) <= d*d){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    solve(v);
    for(int i = 0; i < n; i++){
        if(check[i]) cout << "Yes\n";
        else cout << "No\n";
    }
}