#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll M = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int a[n + 5], b[n + 5];
        vector<int> res;
        multiset<int> s1, s2;
        for(int i = 0; i < n; i++){
            cin >> a[i]; b[i] = a[i];
        } 
        sort(b, b + k);
        int p = (k + 1)/2;
        res.push_back(b[p - 1]);
        int middle = b[p];
        for(int i = 0; i < (k+1)/2; i++) s1.insert(b[i]);
        for(int i = (k + 1)/2; i < k; i++) s2.insert(b[i]);
        for(int i = k; i < n; i++){
            int j = i - k;
            int x = a[i];
            auto it = s1.end(); it--;
            if(x <= *(it)){
                s1.insert(x);
            } else s2.insert(x);
            if(s1.size() > p){
                auto it2 = s1.end(); it2--;
                s2.insert(*it2); s1.erase(it2);
            }
            if(s1.size() < p){
                auto it2 = s2.begin();
                s1.insert(*it2); s2.erase(it2);
            }
            if(s1.find(a[j]) != s1.end()){
                s1.erase(s1.find(a[j]));
            } else{
                s2.erase(s2.find(a[j]));
            }
            if(s1.size() > p){
                auto it2 = s1.end(); it2--;
                s2.insert(*it2); s1.erase(it2);
            }
            if(s1.size() < p){
                auto it2 = s2.begin();
                s1.insert(*it2); s2.erase(it2);
            }
            it = s1.end(); it--;
            res.push_back(*it);
        }
        for(auto x : res) cout << x << " ";
        cout << endl;
    }
}
// 2
// 8 5
// 1 3 -1 -3 5 3 6 7
// 6 1
// 5 4 3 2 1 0