#include <bits/stdc++.h>
using namespace std;

void solve() {
		int n;
		cin >> n;
		vector<int> a(n);
		int x = 0;
		for (int i = 0; i < n; i++) {
				cin >> a[i];
				x ^= a[i]; // accumulate total XOR of the array
		}
		if (x == 0) { // if total XOR is 0, we can always make all elements equal (with >= 2 left)
				cout << "YES\n";
				return;
		}

		// Find the earliest prefix whose XOR equals x
		int pr = 0, pr_ind = -1;
		for (int i = 0; i < n; i++) {
				pr ^= a[i];
				if (pr == x) {
						pr_ind = i; // prefix [0..i] has XOR x
						break;
				}
		}

		// Find the latest suffix whose XOR equals x
		int suf = 0, suf_ind = -1;
		for (int i = n - 1; i >= 0; i--) {
				suf ^= a[i];
				if (suf == x) {
						suf_ind = i; // suffix [i..n-1] has XOR x
						break;
				}
		}

		// If prefix ends before suffix starts, there's a non-empty middle segment -> can partition into 3 parts with XOR x
		if (suf_ind > pr_ind)
				cout << "YES\n";
		else
				cout << "NO\n";
}

/*
Time Complexity (TC): O(n)
Space Complexity (SC): O(n)
*/

int32_t main() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int t;
		cin >> t;
		while (t--) {
				solve();
		}

		return 0;
}
