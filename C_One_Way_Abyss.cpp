#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> at(n + 1);
    vector<int> value(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        at[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int x, y, v;
        cin >> x >> y >> v;

        int a = at[x];
        int b = at[y];

        value[a] += v;
        value[b] += v;

        swap(at[x], at[y]);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans = max(ans, value[i]);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}