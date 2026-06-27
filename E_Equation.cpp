#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    double c;
    cin >> c;
    auto get = [&] (double x) -> double {
        return x * x + sqrt(x);
    };
    double l = 0.0, r = 1e9;
    for (int i = 0; i < 200; ++i) {
        double mid = (l + r) / 2.0;
        if (get(mid) >= c) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(15) << l << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) run();
    return 0;
}