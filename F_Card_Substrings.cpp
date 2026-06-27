#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    string m; cin >> m;

    map<char, int> freq, curr;

    for (char c : m) {
        freq[c]++;
    }

    int l = 0, ans = 0;

    for (int r = 0; r < s.size(); r++) {
        curr[s[r]]++;

        while (curr[s[r]] > freq[s[r]]) {
            curr[s[l]]--;
            l++;
        }

        ans += (r - l + 1);
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    run();
    return 0;
}