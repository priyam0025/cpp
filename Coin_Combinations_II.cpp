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
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define maxel(x) (*max_element(all(x)))
#define minel(x) (*min_element(all(x)))
#define let(n) \
    int n;     \
    cin >> n;
#define let2(a, b) \
    int a, b;      \
    cin >> a >> b;
#define let3(a, b, c) \
    int a, b, c;      \
    cin >> a >> b >> c;
#define leta(arr, n)            \
    vi arr(n);                  \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define print(...) cout << __VA_ARGS__ << endl
#define YN(f) cout << (f ? "YES" : "NO") << endl

const int INF = 2e18;
const int mod = 1e9 + 7;
const int mod2 = 998244353;

int ipow(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

void printa(const vi &a)
{
    for (auto x : a)
        cout << x << ' ';
    cout << endl;
}

void solve()
{
    let2(n, x);
    leta(b, n);

    vector<int> prev(x + 1, 0), cur(x + 1, 0);

    // vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    // vector<vector<int>> dp(n, vector<int>(x + 1, -1));

    // auto f = [&](auto &&self, int idx, int sum) -> int  // memoization
    // {
    //     if (sum < 0)
    //         return 0;

    //     if (idx == 0)
    //         return (sum % b[0] == 0);

    //     if (dp[idx][sum] != -1)
    //         return dp[idx][sum];

    //     int take = self(self, idx, sum - b[idx]) % mod;

    //     int skip = self(self, idx - 1, sum) % mod;

    //     return dp[idx][sum] = (take + skip) % mod;
    // };

    // for (int sum = 0; sum <= x; ++sum) {     // base case
    //     if (sum % b[0] == 0) dp[0][sum] = 1;
    // }

    // for (int idx = 1; idx < n; ++idx) {      // tabulation
    //     for (int sum = 0; sum <= x; ++sum) {
    //         int take = 0;
    //         if (sum - b[idx] >= 0)
    //             take = dp[idx][sum - b[idx]] % mod;

    //         int skip = dp[idx - 1][sum] % mod;

    //         dp[idx][sum] = (take + skip) % mod;
    //     }
    // }

    for (int sum = 0; sum <= x; ++sum) {     // base case
        if (sum % b[0] == 0) prev[sum] = 1;
    }

    for (int idx = 1; idx < n; ++idx) {      // space optimization 
        for (int sum = 0; sum <= x; ++sum) {
            int take = 0;
            if (sum - b[idx] >= 0)
                take = cur[sum - b[idx]] % mod;

            int skip = prev[sum] % mod;        // this is got accepted in cses !!!

            cur[sum] = (take + skip) % mod;
        }
        prev = cur;
    }

    // cout << f(f, n - 1, x) << '\n';
    // cout << dp[n - 1][x] << '\n';
    cout << prev[x] << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; // cin >> tt;  // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++)
    {
        solve();
    }
    return 0;
}