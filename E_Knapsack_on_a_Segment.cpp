#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, s;
    cin >> n >> s;
    vector<int> w(n), c(n);
    for (int &i : w) cin >> i;
    for (int &i : c) cin >> i;
    int l = 0;
    int r = 0;
    int sum_w = 0, sum_c = 0;
    int ans = 0;

    while(r < n) {
        sum_w += w[r];
        sum_c += c[r];

        while (sum_w > s) {
            sum_w -= w[l];
            sum_c -= c[l];
            l++;
        }

        ans = max(ans, sum_c);
        r++;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) run();
    return 0;
}