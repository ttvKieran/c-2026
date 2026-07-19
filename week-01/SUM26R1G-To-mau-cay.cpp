#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n; cin >> n;
    vector<vector<pair<int, int>>> v(n + 5);
    for(int i = 0; i < n - 1; i++){
        int x, y; cin >> x >> y;
        v[x].push_back({y, i});
        v[y].push_back({x, i});
    }
    vector<int> color(n + 5, -1);
    vector<int> parentColor(n + 5, 0);
    vector<bool> visited(n + 5, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        int curr = 1;
        for(int i = 0; i < v[x].size(); i++){
            int a = v[x][i].first;
            int index = v[x][i].second;
            if(!visited[a]){
                if(curr == parentColor[x]) curr++;
                color[index] = curr;
                parentColor[a] = curr;
                visited[a] = true;
                q.push(a);
                curr++;
            }
        }
        // for(int i = 0; i < n; i++) cout << color[i] << " ";
        // cout << endl;
        // for(int i = 1; i <= n; i++) cout << parentColor[i] << " ";
        // cout << endl;
        // for(int i = 1; i <= n; i++) cout << visited[i] << " ";
        // cout << endl;
        // cout << endl;
    }
    int res = 0;
    for(int i = 0; i < n - 1; i++) res = max(res, color[i]);
    cout << res << endl;
    for(int i = 0; i < n - 1; i++) cout << color[i] << " ";
}