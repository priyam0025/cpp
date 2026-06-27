#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    auto can = [&](int x) -> bool {
        int curSum = 0;
        int segs = 1;
        for (int i = 0; i < n; ++i) {
            curSum += a[i];
            if (curSum > x) {
                curSum = a[i];
                segs++;
            } else continue;
        }
        return segs <= k;
    };
    int l = *max_element(a.begin(), a.end());
    int r = accumulate(a.begin(), a.end(), 0LL);
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (can(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
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