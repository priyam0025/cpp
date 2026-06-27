#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int press[3][3];
    int light[3][3];

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            light[i][j] = 1;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> press[i][j];

    int dx[5] = {0, 0, 0, 1, -1};
    int dy[5] = {0, 1, -1, 0, 0};

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(press[i][j] % 2 == 1) {
                for(int k = 0; k < 5; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if(ni >= 0 && ni < 3 && nj >= 0 && nj < 3)
                        light[ni][nj] ^= 1;
                }
            }
        }
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++)
            cout << light[i][j];
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) run();
    return 0;
}