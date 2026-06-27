#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int k;
    cin >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        int left = lower_bound(a.begin(), a.end(), l) - a.begin();
        int right = upper_bound(a.begin(), a.end(), r) - a.begin();
        cout << (right - left) << " ";
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) run();
    return 0;
}