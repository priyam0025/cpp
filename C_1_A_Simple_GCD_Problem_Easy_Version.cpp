#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

void run() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (auto &x : a) cin >> x;
    int ans = (a[0] != gcd(a[0], a[1])) + (a[n - 1] != gcd(a[n - 1], a[n - 2]));
    for (int i = 1; i + 1 < n; ++i) {
        if (a[i] != lcm(gcd(a[i], a[i - 1]), gcd(a[i], a[i + 1]))) {
            ans++;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) run();
    return 0;
}