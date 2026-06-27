#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")

#define int long long
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pb push_back
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i <= n; i++)
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define maxel(x) (*max_element(all(x)))
#define minel(x) (*min_element(all(x)))
#define let(n) int n; cin >> n;
#define let2(a, b) int a, b; cin >> a >> b;
#define let3(a, b, c) int a, b, c; cin >> a >> b >> c;
#define leta(arr, n) vi arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define print(...) cout << __VA_ARGS__ << endl
#define YN(f) cout << (f ? "YES" : "NO") << endl

const int INF = 2e18;
const int mod = 1e9 + 7;
const int mod2 = 998244353;

int ipow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

void printa(const vi &a) {
    for (auto x : a) cout << x << ' ';
    cout << endl;
}

void solve() {
    let2(n, x);
    leta(a, n); // prices
    leta(b, n); // no of pages

    // vvi dp(n, vi(x + 1, -1));

    // auto f = [&](auto&& g, int idx, int sum) -> int { // memoization
    //     if (idx == 0) {
    //         if (sum < a[idx]) return 0;
    //         else return b[idx];
    //     }

    //     if (dp[idx][sum] != -1) return dp[idx][sum];

    //     int take = -1e9;
    //     int skip = g(g, idx - 1, sum);
    //     if (sum >= a[idx]) {
    //         take = b[idx] + g(g, idx - 1, sum - a[idx]);
    //     }
    //     return  dp[idx][sum] = max(take, skip);
    // };

    // int ans = f(f, n - 1, x);
    // cout << ans << '\n';

    // vvi dp(n, vi(x + 1, 0));

    // for (int sum = 0; sum <= x; ++sum) {    // tabulation
    //     if (sum < a[0]) dp[0][sum] = 0;
    //     else dp[0][sum] = b[0];
    // }

    // for (int idx = 1; idx < n; ++idx) {
    //     for (int sum = x; sum >= 0; sum--) {
    //         int take = -1e9;
    //         int skip = dp[idx - 1][sum];
    //         if (sum > a[idx]) {
    //             take = b[idx] + dp[idx - 1][sum - a[idx]];
    //         }

    //         dp[idx][sum] = max(take, skip);
    //     }
    // }

    // cout << dp[n - 1][x] << '\n';

    // vi prev(x + 1, 0), cur(x + 1, 0);

    // for (int sum = 0; sum <= x; ++sum) {    // Space optimization
    //     if (sum < a[0]) prev[sum] = 0;
    //     else prev[sum] = b[0];
    // }

    // for (int idx = 1; idx < n; ++idx) {
    //     for (int sum = x; sum >= 0; sum--) {
    //         int take = -1e9;
    //         int skip = prev[sum];
    //         if (sum >= a[idx]) {
    //             take = b[idx] + prev[sum - a[idx]];
    //         }

    //         cur[sum] = max(take, skip);
    //     }

    //     prev = cur;
    // }

    // cout << prev[x] << '\n';

    vi dp(x + 1, 0);

    for (int i = 0; i < n; i++) 
    {
        for (int sum = x; sum >= a[i]; sum--) 
        {
            dp[sum] = max(dp[sum], b[i] + dp[sum - a[i]]);
        }
    }

cout << dp[x];
    
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;  // cin >> tt;  // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++) {
        solve();
    }
    return 0;
}