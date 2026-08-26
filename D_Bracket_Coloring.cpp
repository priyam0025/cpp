#include <bits/stdc++.h>

using namespace std;

void solve() {
		int n;
		cin >> n;
		string s;
		cin >> s;

		vector<int> bal(n);
		bal[0] = (s[0] == '(' ? 1 : -1);
		for (int i = 1; i < n; i++) {
				bal[i] = bal[i - 1] + (s[i] == '(' ? 1 : -1);
		}

		if (bal[n - 1] != 0) {
				cout << -1 << '\n';
				return;
		}

		if (*min_element(bal.begin(), bal.end()) == 0) {
				cout << 1 << '\n';
				for (int i = 0; i < n; i++) cout << 1 << ' ';
				cout << '\n';
				return;
		}
		else if (*max_element(bal.begin(), bal.end()) == 0) {
				cout << 1 << '\n';
				for (int i = 0; i < n; i++) cout << 1 << ' ';
				cout << '\n';
				return;
		}

		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
				if (bal[i] > 0) ans[i] = 1;
				else if (bal[i] < 0) ans[i] = 2;
				else ans[i] = (bal[i - 1] > 0 ? 1 : 2);
		}

		cout << 2 << '\n';
		for (int i = 0; i < n; i++) cout << ans[i] << ' ';
		cout << '\n';
}

int main() {
		int t;
		cin >> t;
		for (int i = 0; i < t; i++) solve();
}

