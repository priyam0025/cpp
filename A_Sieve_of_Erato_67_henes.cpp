#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    if (find(v.begin(), v.end(), 67) != v.end()) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) run();
    return 0;
}