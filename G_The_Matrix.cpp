#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<int> row(n, 0), col(m, 0);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];

            row[i] ^= a[i][j];
            col[j] ^= a[i][j];
        }
    }

    for (int x : row) ans += x;
    for (int x : col) ans += x;

    int best = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            best = max(best, row[i] & col[j]);
        }
    }

    cout << ans - 2 * best << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}