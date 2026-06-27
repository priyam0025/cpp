#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i ++){
			if(a[i] > c)
				break;
			int o = min(k,c - a[i]);
			k -= o;
			c += a[i] + o;
		}
    cout << c << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) run();
    return 0;
}