#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n; cin >> n;
    if (n == 1) {
        cout << n << '\n';
        return;
    }

    if (n < 4 && n != 1) {
        cout << "NO SOLUTION" << '\n';
        return;
    }
    int i = 2;

    while (n >= i) {
        cout << i << " ";
        i += 2;
    }
    i = 1;
    while (i <= n) {
        cout << i << " ";
        i += 2;
    }

}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) run();
    return 0;
}