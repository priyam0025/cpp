#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n; cin >> n;
    vector<int> x(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> v[i];
    }
    auto can = [&](double t) -> bool {
        double L = -1e18, R = 1e18;
        for (int i = 0; i < n; ++i) {
            double l = x[i] - v[i] * t;
            double r = x[i] + v[i] * t;
            L = max(l, L);
            R = min(r, R);
        }
        return L <= R;
    };
    double l = 0.0, r = 1e18;
    for (int it = 0; it < 200; ++it) {
        double mid = (l + r) / 2.0;
        if (can(mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(6) << r <<'\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) run();
    return 0;
}