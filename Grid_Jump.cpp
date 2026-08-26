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
    let2(A, B);
    let3(P, Q, R);
    vector<vector<int>> dp(A + 1, vector<int>(B + 1, INF));

    dp[0][0] = 0;

    for (int x = 0; x <= A; x++) {
        for (int y = 0; y <= B; y++) {
            if (dp[x][y] == INF) continue;

            if (x + 1 <= A)
                dp[x + 1][y] = min(dp[x + 1][y], dp[x][y] + P);

            if (x + 2 <= A)
                dp[x + 2][y] = min(dp[x + 2][y], dp[x][y] + P);

            if (y + 1 <= B)
                dp[x][y + 1] = min(dp[x][y + 1], dp[x][y] + Q);

            if (y + 2 <= B)
                dp[x][y + 2] = min(dp[x][y + 2], dp[x][y] + Q);

            if (x + 1 <= A && y + 1 <= B)
                dp[x + 1][y + 1] = min(dp[x + 1][y + 1], dp[x][y] + R);
        }
    }

    cout << dp[A][B] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;   cin >> tt;  // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++) {
        solve();
    }
    return 0;
}