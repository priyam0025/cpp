#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, x, y;
    cin >> n >> x >> y;

    int t = min(x, y);

    if (n == 1) {
        cout << t << '\n';
        return;
    }

    int l = 0, r = 1e18;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (mid / x + mid / y >= n - 1) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << t + l << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) run();
    return 0;
}