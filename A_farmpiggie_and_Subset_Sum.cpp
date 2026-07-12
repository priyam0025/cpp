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

        vector<int> p(n + 1);
        int even = 2, odd = 1;

        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                p[i] = even;
                even += 2;
            } else {
                p[i] = odd;
                odd += 2;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << p[i] << (i == n ? '\n' : ' ');
        }
    }

    return 0;
}