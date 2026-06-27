#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    int maxi = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            maxi = max(maxi, a[i] ^ a[j]);
        }
    }
    cout << maxi << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) run();
    return 0;
}