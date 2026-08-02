// Dạng LCP nộp ac trước tìm hiểu sau
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();

    // Bước 1: Suffix Array (sắp xếp các vị trí bắt đầu theo thứ tự hậu tố)
    vector<int> sa(n);
    iota(sa.begin(), sa.end(), 0);
    sort(sa.begin(), sa.end(), [&](int i, int j){
        return s.compare(i, string::npos, s, j, string::npos) < 0;
    });

    // Bước 2: LCP array (LCP giữa hậu tố rank i và rank i-1)
    vector<int> lcp(n, 0);
    for(int i = 1; i < n; i++){
        int a = sa[i-1], b = sa[i];
        int len = 0;
        while(a+len < n && b+len < n && s[a+len] == s[b+len]) len++;
        lcp[i] = len;
    }

    // Bước 3: Duyệt tuần tự, đếm xâu con mới, dừng khi đủ K
    long long cnt = 0;
    for(int i = 0; i < n; i++){
        int start = sa[i];
        int suffixLen = n - start;
        for(int len = lcp[i] + 1; len <= suffixLen; len++){
            cnt++;
            if(cnt == k){
                cout << s.substr(start, len);
                return 0;
            }
        }
    }
}