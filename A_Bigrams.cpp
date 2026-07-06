#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        bool ok = false;
        int cntTwo = 0;

        for (int i = 0; i < k; i++) {
            long long x;
            cin >> x;

            if (x >= 3)
                ok = true;
            else if (x == 2)
                cntTwo++;
        }

        if (!ok && cntTwo >= 2)
            ok = true;

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}