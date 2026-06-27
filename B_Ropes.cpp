#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &i : a) cin >> i;

    double l = 0.0, r = *max_element(a.begin(), a.end());

    auto get = [&](double x) -> long long {
        long long c = 0;
        for (auto i : a) {
            c += (long long)(i / x);
        }
        return c;
    };

    for (int i = 0; i < 200; i++) {
        double mid = (l + r) / 2.0;

        if (get(mid) >= k) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << fixed << setprecision(10) << l << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) run();
    return 0;
}