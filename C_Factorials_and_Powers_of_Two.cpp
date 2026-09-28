#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

vector<int> fact;
unordered_map<int, int> dp;

void generateFactorials() {
    int f = 1;

    for (int i = 1; i <= 15; i++) {
        f *= i;

        if (f > 1e12)
            break;

        fact.push_back(f);
    }
}

int f(int idx, int rem) {
    if (idx == (int)fact.size()) {
        return __builtin_popcountll(rem);
    }

    int key = idx * 1000000000001LL + rem;

    if (dp.count(key))
        return dp[key];

    // Don't take current factorial
    int skip = f(idx + 1, rem);

    // Take current factorial
    int take = INF;

    if (fact[idx] <= rem) {
        take = 1 + f(idx + 1, rem - fact[idx]);
    }

    return dp[key] = min(take, skip);
}

void solve() {
    int n;
    cin >> n;

    dp.clear();

    cout << f(0, n) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    generateFactorials();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}