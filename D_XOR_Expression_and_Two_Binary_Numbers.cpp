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
    let2(n, k);

    string s, z;
    cin >> s >> z;

    long long x1 = 0, x2 = 0, x3 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') x1++;
        if (z[i] == '1') x2++;
        if (s[i] != z[i]) x3++;
    }

    long long a = x1, b = x2;

    long long y1 = n - x1;
    long long y2 = n - x2;
    long long y3 = n - x3;

    x1 *= y1;
    x2 *= y2;
    x3 *= y3;
    long long p = (1LL << k) + 1;
    long long r1 = p / 3;
    long long r2 = p % 3;

    x1 *= r1;
    x2 *= r1;
    x3 *= r1;

    if (r2 == 1) {
        x1 += a * y1;
    } else if (r2 == 2) {
        x1 += a * y1;
        x2 += b * y2;
    }

    cout << x1 + x2 + x3 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;   cin >> tt;  // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++) {
        solve();
    }
    return 0;
}