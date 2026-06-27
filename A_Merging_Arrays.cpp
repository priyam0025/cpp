#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), c(n + m); 
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int j = 0; j < m; ++j) cin >> b[j];
    int l = 0, r = 0;
    int idx = 0;
    while (l < n && r < m) {
        if (a[l] <= b[r]) {
            c[idx++] = a[l++];
        } else {
            c[idx++] = b[r++];
        }
    }
    while (l < n) c[idx++] = a[l++];
    while (r < m) c[idx++] = b[r++];
    for (auto x : c) cout << x << " ";
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) run();
    return 0;
}