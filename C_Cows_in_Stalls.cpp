#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    auto can = [&](int dist) {
        int cows = 1;
        int last = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] - last >= dist) {
                cows++;
                last = a[i];
            }
        }
        return cows >= k;
    };
    int l = 0;
    int r = a[n - 1] - a[0];
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (can(mid)) {
            ans = mid;
            l = mid + 1;   
        } else {
            r = mid - 1;  
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    run();
    return 0;
}