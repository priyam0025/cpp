#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    vector<pair<int, int>> prev;
    int ans = INT_MAX;
    for (int i = 0; i < n ; ++i) {
        vector<pair<int, int>> curr;
        curr.push_back({a[i], 1});

        for (auto [g, l] : prev) {
            int ng = __gcd(g, a[i]);
            if (curr.back().first == ng) {
                curr.back().second = min(curr.back().second, l + 1);
            } else {
                curr.push_back({ng, l + 1});
            }
        }
        for (auto [g, len] : curr) {
            if (g == 1) {
                ans = min(ans, len);
            }
        }

        prev = curr;
        
    }
    cout << (ans == INT_MAX ? -1 : ans) << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) run();
    return 0;
}