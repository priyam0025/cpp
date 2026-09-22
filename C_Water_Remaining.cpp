#include <bits/stdc++.h>
using namespace std;

#define int long long

void run(int n) {
    vector<int> v(n);
    for (int &i : v) cin >> i;
    int maxi = *max_element(v.begin(), v.end());
    for (int &x : v) {
        x = maxi - x;
    }
    vector<int> l(n), r(n);
    l[0] = v[0];
    for (int i = 1; i < n; ++i) {
        l[i] = max(l[i - 1], v[i]);
    }
    r[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        r[i] = max(r[i + 1], v[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += min(r[i], l[i]) - v[i];
    }
    cout << ans << "\n";

}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while(true) {
        int n;
        cin  >> n;
        if (n == 0) break;
        else run(n);
    }
    return 0;
}