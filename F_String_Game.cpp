#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    string t, p;
    cin >> t >> p;
    vector<int> a(t.size());
    for (int &i : a) cin >> i;
    auto get = [&](int x) -> bool {
        vector<bool> removed(t.size(), false);
        for (int i = 0; i < x; ++i) {
            removed[a[i] - 1] = true;
        }
        int j = 0; //pointer for p // check if p is a subsequence
        for (int i = 0; i < t.size(); ++i) {
            if (!removed[i] && t[i] == p[j]) {
                j++;
                if (j == p.size()) return true;
            }
        }
        return false;
    };
    int l = 0, r = t.size();
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (get(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
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