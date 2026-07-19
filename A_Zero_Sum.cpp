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

        int ones = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 1) ones++;
        }

        if (n % 2 == 0 && (abs(ones - n / 2) % 2 == 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}