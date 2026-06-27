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

        vector<int> p(n), a(n), pos(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            pos[p[i]] = i;
        }
        for (int i = 0; i < n; i++) cin >> a[i];

        bool cazz = true;
        vector<int> seen(n + 1, 0);
        int lastP = -1;
        int lastVal = -1;

        for (int i = 0; i < n; i++) {
            if (a[i] != lastVal) {
                if (seen[a[i]]) {
                    cazz = false;
                    break;
                }
                seen[a[i]] = 1;

                if (pos[a[i]] < lastP) {
                    cazz = false;
                    break;
                }
                
                lastP = pos[a[i]];
                lastVal = a[i];
            }
        }

        cout << (cazz ? "YES\n" : "NO\n");
    }

    return 0;
}