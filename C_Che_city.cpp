#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, r;
    cin >> n >> r;
    vector<int> d(n);
    for (int &i : d) cin >> i;
    int i = 0, j = 0, ans = 0;
    while (j < n) {
        int diff = d[j] - d[i];
        while (diff > r) {
            ans += (n - j);
            diff -= d[i + 1] - d[i];
            i++;
        }
        j++;
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