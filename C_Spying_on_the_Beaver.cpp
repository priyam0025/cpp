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
    let(n);

    vi p(n + 1);
    vector<vi> adj(n + 1);
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        adj[p[i]].pb(i);
    }

    let(m);
    vector<bool> hasDam(n + 1, false);
    for (int i = 0; i < m; ++i) {
        let(a);
        hasDam[a] = true;
    }

    vi damfreq(n + 1, 0);
    for (int i = n; i >= 1; --i) {
        if (hasDam[i]) {
            damfreq[i]++;
        }
        if (i > 1) {
            damfreq[p[i]] += damfreq[i];
        }
    }

    vi cam;

    for (int u = 1; u <= n; ++u) {
        if (damfreq[u] == 0) continue;

        vi actvChild;
        for (int v : adj[u]) {
            if (damfreq[v] > 0) {
                actvChild.pb(v);
            }
        }

        int c = sz(actvChild);
        if (c == 0) continue;

        if (hasDam[u]) {
            for (int v : actvChild) {
                cam.pb(v);
            }
        } else {
            rep(i, c - 1) {
                cam.pb(actvChild[i]);
            }
        }
    }

    cout << sz(cam);
    for (int v : cam) {
        cout << " " << v;
    }
    cout << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;   cin >> tt;  // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++) {
        solve();
    }
    return 0;
}