#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int s = 0;
    for (auto &i : a) {
        cin >> i;
        s += i;
    }
    if (s & 1) {
        cout << "YES\n";
    } else if ((k * n) % 2 == 0) {
        cout << "YES\n";
    } else cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) run();
    return 0;
}