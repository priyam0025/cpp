#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, m, k; 
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int &i: a) cin >> i;
    for (int &i: b) cin >> i;
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    int i = 0; int j = 0;
    int ans = 0;

    while (j < m && i < n) {
        if (abs(a[i] - b[j]) <= k) {
            i++;
            j++;
            ans++;
        } else if (b[j] < a[i] - k) {
            j++;
        } else 
            i++;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) run();
    return 0;
}