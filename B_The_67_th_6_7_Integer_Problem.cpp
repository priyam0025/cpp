#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    vector<int> a(7);
    int total = 0;
    
    for (int i = 0; i < 7; i++) {
        cin >> a[i];
        total += a[i];
    }
    
    int mx = *max_element(a.begin(), a.end());
    
    int ans = -total + 2 * mx;
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) run();
    return 0;
}