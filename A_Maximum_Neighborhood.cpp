#include <bits/stdc++.h>
 
using namespace std;
 
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        auto get = [&](int x, int y) {
            if (x >= 0 && x < n && y >= 0 && y < n) return x * n + y + 1;
            return 0;
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int cur = get(i, j);
                for (int d = 0; d < 4; ++d) cur += get(i + dx[d], j + dy[d]);
                ans = max(ans, cur);
            }
        }
        cout << ans << '\n';
    }
}
