#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n; cin >> n;
    int k; cin >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int l = 0 , r = 0, d = 0;
    int ans = 0;
    map<int, int> freq;
    while (r < n) {
        if (freq[v[r]] == 0) {
            d++;
        }
        freq[v[r]]++;
        while (d > k) {
            freq[v[l]]--;
            if (freq[v[l]] == 0) {
                d--;
            }
            l++;
        }
        ans += (r - l + 1);
        r++;
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