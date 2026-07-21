#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        if (a == b) {
            cout << 0 << '\n';
            continue;
        }

        int sum = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                sum += a[i];
            }
        }
        
        if (accumulate(a.begin(), a.end(), 0) == 0 || accumulate(b.begin(), b.end(), 0) == n) {
            cout << -1 << "\n";
            continue;
        }

        if (sum % 2 == 1) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
    
    return 0;
}