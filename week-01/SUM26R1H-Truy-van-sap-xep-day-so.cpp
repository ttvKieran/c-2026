#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    multiset<int> core;
    deque<int> q;

    while(t--){
        int type; cin >> type;
        if(type == 1){
            int x; cin >> x;
            q.push_back(x);
        } else if(type == 2){
            if(!core.empty()){
                cout << *core.begin() << "\n";
                core.erase(core.begin());
            } else {
                cout << q.front() << "\n";
                q.pop_front();
            }
        } else { 
            for(int v : q) core.insert(v);
            q.clear();
        }
    }
}