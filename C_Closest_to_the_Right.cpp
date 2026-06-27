#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    auto rightClosest = [&](int x) -> int {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] >= x) r = mid - 1;
        else l = mid + 1;
    }
    return l + 1;
};

    for (int i = 0; i < k; ++i) {
        int x; 
        cin >> x;
        cout << rightClosest(x) << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) run();
    return 0;
}