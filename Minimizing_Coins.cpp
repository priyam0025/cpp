#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")

#define int long long
#define vi vector<int>
#define let2(a, b) int a, b; cin >> a >> b;
#define leta(arr, n) vi arr(n); for(int i = 0; i < n; i++) cin >> arr[i];

const int INF = 1e18;

void solve() {

    let2(n, x);
    leta(c, n);

    vector<int> dp(x + 1, INF);

    dp[0] = 0;

    for (int coin : c) {

        for (int target = coin; target <= x; ++target) {

            dp[target] = min(dp[target],
                             1 + dp[target - coin]);
        }
    }

    if (dp[x] >= INF) {
        cout << -1 << '\n';
    } else {
        cout << dp[x] << '\n';
    }
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}