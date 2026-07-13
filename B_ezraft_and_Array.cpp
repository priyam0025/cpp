#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        if (n == 2) {
            cout << -1 << '\n';
            continue;
        }

        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }

        cout << "1 2 3";
        long long cur = 6;

        for (int i = 4; i <= n; i++) {
            cout << " " << cur;
            cur *= 2;
        }
        cout << '\n';
    }

    return 0;
}