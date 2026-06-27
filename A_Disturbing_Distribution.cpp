#include <bits/stdc++.h>
using namespace std;

const long long MOD = 676767677;

int n;
vector<long long> a;

// dp[i][last] → use map because last is large
map<pair<int, long long>, long long> dp;

long long f(int i, long long last) {
    if (i == n) return last % MOD;

    auto key = make_pair(i, last);
    if (dp.count(key)) return dp[key];

    long long res = LLONG_MAX;

    // Option 1: continue subsequence
    if (a[i] >= last) {
        res = min(res, f(i + 1, a[i]));
    }

    // Option 2: break here
    long long break_cost = (last + f(i + 1, a[i])) % MOD;
    res = min(res, break_cost);

    return dp[key] = res % MOD;
}

void solve() {
    cin >> n;
    a.resize(n);
    for (auto &x : a) cin >> x;

    dp.clear();

    cout << f(1, a[0]) % MOD << '\n';
}       

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;   cin >> tt;  // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++) {
        solve();
    }
    return 0;
}