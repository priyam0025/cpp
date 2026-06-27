#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int i = 0, j = 0, ans = 0;
    multiset<int> ms;
    while (j < n) {
        ms.insert(a[j]);
        while(*ms.rbegin() - *ms.begin() > k) {
            ms.erase(ms.find(a[i]));
            i++;
        }
        ans += j - i + 1;
        j++;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) run();
    return 0;
}