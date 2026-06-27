#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int l = 0, r = 0;
    int sum = 0; int cnt = 0;
    while (r < n) {
        sum += a[r];
        while (sum > s) {
            sum -= a[l];
            l++;
        }
        cnt += (r - l + 1) * (r - l + 2) / 2;
        r++;
    } 
    cout << cnt << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) run();
    return 0;
}