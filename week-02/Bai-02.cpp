#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void rec(int x, int y, int i, int j) {
    for (int k = 0; k < 4; k++) {
        int ni=i + dx[k];
        int nj=j + dy[k];
        if (ni>=0&&ni<x&& nj>= 0&& nj< y &&m[ni][nj]=='O') {
            m[ni][nj] = 'K'; 
            rec(x, y, ni, nj); 
        }
    }
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int x, y;
        cin >> x >> y;
        m.assign(x, vector<char>(y, 'X'));
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                cin >> m[i][j];
            }
        }
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                if((i ==0|| i==x-1 || j==0 || j==y-1) && m[i][j]=='O'){
                    m[i][j] = 'K'; 
                    rec(x, y, i, j);
                }
            }
        }
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                if(m[i][j] == 'K') cout << 'O';
                else cout << 'X';
                cout << " ";
            }
            cout << endl;
        }
    }
}

// 1 3 2 1 3 2 1 3 2 1 3 2

// (3+2+1+4+3+2+1) (3+2+1) 


