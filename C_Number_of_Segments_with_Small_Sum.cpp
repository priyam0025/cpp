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
        int cnt = 0;
        while (r < a.size()) {
            sum += a[r];
            while (sum > x) {
                sum -= a[l];
                l++;
            }
            cnt += (r - l + 1);;
            r++;
        }
        return cnt;
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