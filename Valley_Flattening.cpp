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
    int n;
    cin >> n;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<bool> is_center(n + 1, false);
    for (int i = 2; i <= n - 1; i++) {
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            is_center[i] = true;
        }
    }

    vector<vector<long long>> dp(2, vector<long long>(2, INF));

    dp[0][0] = a[1];
    if (is_center[2]) {
        dp[0][1] = a[2];
    }

    for (int i = 2; i <= n - 2; i++) {
        vector<vector<long long>> next_dp(2, vector<long long>(2, INF));

        for (int c_prev = 0; c_prev <= 1; c_prev++) {
            for (int c_curr = 0; c_curr <= 1; c_curr++) {
                if (dp[c_prev][c_curr] == INF) continue;

                for (int c_next = 0; c_next <= 1; c_next++) {
                    if (c_next == 1 && (!is_center[i + 1] || c_curr == 1)) continue;

                    long long val_i;
                    if (c_curr == 1) {
                        val_i = a[i];
                    } else if (c_prev == 1 && c_next == 1) {
                        val_i = min(a[i - 1], a[i + 1]);
                    } else if (c_prev == 1) {
                        val_i = a[i - 1];
                    } else if (c_next == 1) {
                        val_i = a[i + 1];
                    } else {
                        val_i = a[i];
                    }

                    next_dp[c_curr][c_next] = min(next_dp[c_curr][c_next], dp[c_prev][c_curr] + val_i);
                }
            }
        }
        dp = next_dp;
    }

    long long ans = INF;

    for (int c_prev = 0; c_prev <= 1; c_prev++) {
        for (int c_curr = 0; c_curr <= 1; c_curr++) {
            if (dp[c_prev][c_curr] == INF) continue;

            long long val_n_minus_1;
            if (c_curr == 1) {
                val_n_minus_1 = a[n - 1];
            } else if (c_prev == 1) {
                val_n_minus_1 = a[n - 2];
            } else {
                val_n_minus_1 = a[n - 1];
            }

            long long val_n;
            if (c_curr == 1) {
                val_n = a[n - 1];
            } else {
                val_n = a[n];
            }

            ans = min(ans, dp[c_prev][c_curr] + val_n_minus_1 + val_n);
        }
    }

    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;  cin >> tt;  // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++) {
        solve();
    }
    return 0;
}