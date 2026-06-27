#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n;
    cin >> n;

    vector<int> a;
    int l = 1, r = 3 * n;

    while (l < r) {
        a.push_back(l);
        a.push_back(r - 1);
        a.push_back(r);
        l++;
        r -= 2;
    }

    for (int v : a) cout << v << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) run();
    return 0;
}