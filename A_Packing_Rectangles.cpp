#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int w, h, n;
    cin >> w >> h >> n;
    auto get = [&] (int x) -> bool {
        return (x / w) * (x / h) >= n;
    };
    int l = 0, r = 1;
    while ((r / w) * (r / h) < n) {
        r *= 2;
    }
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (get(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
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