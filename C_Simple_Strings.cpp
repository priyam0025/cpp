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
    string s;
    cin >> s;
    int n = sz(s);
    vector<char> ans(n);
    ans[0] = s[0];
    rep1(i, n - 1) {
        if (s[i] == ans[i - 1]) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != s[i - 1]) {
                    if (i < n - 1 and s[i + 1] != c) {
                        ans[i] = c;
                        break;
                    } else if (i == n - 1) {
                        ans[i] = c;
                        break;
                    }
                }
            }
        } else {
            ans[i] = s[i];
        }
    }
    rep(i, n) {
        cout << ans[i];
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;  // cin >> tt;  // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++) {
        solve();
    }
    return 0;
}