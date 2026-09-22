#include <bits/stdc++.h>
using namespace std;

#define int long long

void run(int n, int d) {
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    int cnt = 1;
    int pos = v[0] + d;
    for (int i = 1; i < n; ++i) {
        if (v[i] - pos <= d) continue;
        else {
            cnt++;
            pos = v[i] + d;
        }
    }
    cout << cnt << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while(true) {
        int n, d;
        cin  >> n >> d;
        if (n == 0 and d == 0) break;
        else run(n, d);
    }
    return 0;
}