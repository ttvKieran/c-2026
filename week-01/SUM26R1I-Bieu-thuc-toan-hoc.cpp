#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt = 0;
int op[15];

ll calculate(ll n, ll a[]) {
    stack<ll> st;
    st.push(a[0]);

    for (int i = 0; i < n - 1; i++) {
        if (op[i] == 0) { 
            st.push(a[i + 1]);
        } else if (op[i] == 1) { 
            st.push(-a[i + 1]);
        } else { 
            ll top = st.top();
            st.pop();
            st.push(top * a[i + 1]);
        }
    }
    ll res = 0;
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

void Try(int x, ll n, ll m, ll a[]) {
    for (int i = 0; i < 3; i++) {
        op[x] = i; 
        if (x == n - 2) { 
            ll result = calculate(n, a);
            if (result % m == 0) {
                cnt++;
            }
        } else {
            Try(x + 1, n, m, a);
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--){
        cnt = 0;
        ll n, m; cin >> n >> m;
        ll a[n + 5];
        for(int i = 0; i < n; i++) cin >> a[i];
        if (n == 1) { 
            if (a[0] % m == 0) cout << 1 << "\n";
            else cout << 0 << "\n";
            continue;
        }
        Try(0, n, m, a);
        cout << cnt << endl;
    }
    return 0;
}