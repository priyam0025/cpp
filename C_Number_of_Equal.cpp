#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int i = 0, j = 0, ans = 0;
    while (i < n && j < m) {
        if (a[i] > b[j]) {
            j++;
        }
        else if (a[i] < b[j]) {
            i++;
        } 
        else {
            int val = a[i];
            int cnta = 0, cntb = 0;
            while (i < n && a[i] == val) {
                cnta++;
                i++;
            }
            while (j < m && b[j] == val) {
                cntb++;
                j++;
            }
            ans += cnta * cntb;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) run();
    return 0;
}