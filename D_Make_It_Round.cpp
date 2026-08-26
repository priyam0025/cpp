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

int p2[19];
int p5[19];

void solve() {
    let2(n, m);
    int tmp = n;
    int c2 = 0, c5 = 0;

    while (tmp % 2 == 0) {
        c2++;
        tmp /= 2;
    }
    tmp = n;

    while (tmp % 5 == 0) {
        c5++;
        tmp /= 5;
    }

    for (int dig = 18; dig >= 0; dig--) {
        int extra2 = max(0LL, dig - c2);
        int extra5 = max(0LL, dig - c5); 
        int need = p2[extra2] * p5[extra5];
        if (need <= m) {
            int largestK = m - m % need;
            cout << 1LL * largestK * n << '\n';
            return;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;   cin >> tt;  // Uncomment for multiple test cases
    
    p2[0] = 1;
    p5[0] = 1;

    rep1(i, 18) {
        p2[i] = p2[i - 1] * 2;
        p5[i] = p5[i - 1] * 5; 
    }

    for (int t = 1; t <= tt; t++) {
        solve();
    }
    return 0;
}