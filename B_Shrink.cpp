#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);

    p[0] = 1;
    
    int val = 2;
    for (int i = 1; i < n; i += 2) {
        if (i + 1 < n) {
            p[i] = val + 1;
            p[i + 1] = val;
            val += 2;
        } else {
            p[i] = val;
        }
    }

    for (int x : p) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}
