#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, p; 
    cin >> n >> p;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int s = accumulate(a.begin(), a.end(), 0LL);
    int cyc = p / s;
    int rem = p % s;
    if (rem == 0) {
        cout << 1 << ' ' << cyc * n << '\n';
        return;
    }
    vector<int> b(2 * n);
    for (int i = 0; i < 2 * n ; ++i) {
        b[i] = a[i % n];
    }
    int i = 0, j = 0, pos = 0, minLen = LLONG_MAX;
    int mood = 0;
    while (j < 2 * n) {
        mood += b[j];
        while (mood >= rem) {
            if (j - i + 1 < minLen) {
                minLen = j - i + 1;
                pos = i;
            }
            mood -= b[i];
            i++;
        }
        j++;
    }
    cout << (pos % n) + 1 << " " << minLen + cyc * n << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) run();
    return 0;
}