#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(m, vector<int>(n));
    for (int j = 0; j < n; j++)
		for (int i = 0; i < m; i++)
			cin >> v[i][j];
    for (int i = 0; i < m; i++)
		sort(v[i].begin(), v[i].end());  
	int ans = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++){
				ans -= (v[i][j] * (n - j - 1));
				ans += (v[i][j] * j);
			}
	cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) run();
    return 0;
}