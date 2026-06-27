#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    auto bro = [&](vector<int> a, int x) -> int {
        int l = 0, r = 0;
        int sum = 0;
        int minLen = 1e9; 
        while (r < a.size()) {
            sum += a[r];
            while (sum >= x) {
                minLen = min(minLen, r - l + 1);
                sum -= a[l];
                l++;
            }
            r++;
        }
        return minLen == 1e9 ? -1 : minLen;
    };
    int ans = bro(a, s);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) run();
    return 0;
}