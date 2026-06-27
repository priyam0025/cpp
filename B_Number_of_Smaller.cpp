#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, m; cin >> n >> m;
    vector<int> a(n) , b(m), ans(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int j = 0; j < m; ++j) cin >> b[j];
    int l = 0, r = 0;
    while (r < m) {
        while(a[l] < b[r]) l++;
        ans[r] = l > a.size() ? a.size() : l;
        r++;
    }
    for (int x : ans) cout << x << ' ';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) run();
    return 0;
}