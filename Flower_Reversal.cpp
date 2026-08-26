#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")

#define int long long
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pb push_back
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i <= n; i++)
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define maxel(x) (*max_element(all(x)))
#define minel(x) (*min_element(all(x)))
#define let(n) int n; cin >> n;
#define let2(a, b) int a, b; cin >> a >> b;
#define let3(a, b, c) int a, b, c; cin >> a >> b >> c;
#define leta(arr, n) vi arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define print(...) cout << __VA_ARGS__ << endl
#define YN(f) cout << (f ? "YES" : "NO") << endl

const int INF = 2e18;
const int mod = 1e9 + 7;
const int mod2 = 998244353;

int ipow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

void printa(const vi &a) {
    for (auto x : a) cout << x << ' ';
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        ans += (s[i] == s[i + 1]);
    }

    int c01 = 0, c10 = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == '0' && s[i + 1] == '1') c01++;
        if (s[i] == '1' && s[i + 1] == '0') c10++;
    }

    int g = 0;
    if (c01 >= 2 || c10 >= 2) g = max(g, 2LL);
    if (c01 >= 1 && c10 >= 1) g = max(g, 1LL);

    for (int i = 0; i + 1 < n; i++) {
        int d1 = (s[0] == s[i + 1] ? 1LL : 0LL) - (s[i] == s[i + 1] ? 1LL : 0LL);
        int d2 = (s[i] == s[n - 1] ? 1LL : 0LL) - (s[i] == s[i + 1] ? 1LL : 0LL);
        g = max(g, d1);
        g = max(g, d2);
    }

    cout << ans + g << "\n";
}


int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;   cin >> tt;  // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++) {
        solve();
    }
    return 0;
}