#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[5005];

vector<int> bfsDist(int start, int blockedFrom, int blockedTo) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if ((u == blockedFrom && v == blockedTo) || (u == blockedTo && v == blockedFrom)) 
                continue; 
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int radiusOfComponent(int start, int bf, int bt) {
    vector<int> d1 = bfsDist(start, bf, bt);
    int A = start;
    for (int i = 1; i <= n; i++) 
        if (d1[i] != -1 && d1[i] > d1[A]) A = i;
    vector<int> d2 = bfsDist(A, bf, bt);
    int B = A;
    for (int i = 1; i <= n; i++) 
        if (d2[i] != -1 && d2[i] > d2[B]) B = i;
    int diameter = d2[B];
    return (diameter + 1) / 2; 
}

int main(){
    cin >> n;
    vector<pair<int,int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u, v};
    }
    if (n == 1) { cout << 0; return 0; }
    int ans = INT_MAX;
    for (auto [u, v] : edges) {
        int r1 = radiusOfComponent(u, u, v);
        int r2 = radiusOfComponent(v, u, v);
        ans = min(ans, max(r1, r2));
    }
    cout << ans << "\n";
}