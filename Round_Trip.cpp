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

const long long INF = 2e18;
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
    let2(n, m);

    vvi adj(n + 1);
    vi parent(n + 1, -1);
    vector<bool> vis(n + 1, false);

    rep(i, m) {
        let2(x, y);
        adj[x].pb(y);
        adj[y].pb(x);
    }

    queue<pii> q; // {node, parent}

    int start = -1, end = -1;
    bool found = false;

    for (int i = 1; i <= n; i++) {

        if (vis[i]) continue;

        q.push({i, -1});
        vis[i] = true;

        while (!q.empty() && !found) {

            auto [u, par] = q.front();
            q.pop();

            for (auto v : adj[u]) {

                if (!vis[v]) {

                    vis[v] = true;
                    parent[v] = u;
                    q.push({v, u});
                }

                else if (v != par) {

                    found = true;
                    start = u;
                    end = v;
                    break;
                }
            }

            if (start != -1) break;
        }

        if (start != -1) break;
    }
    if (start == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    // reconstruct cycle

    vi path1, path2;

    int u = start;
    int v = end;

    while (u != v) {

        if (u != -1) {
            path1.pb(u);
            u = parent[u];
        }

        if (v != -1) {
            path2.pb(v);
            v = parent[v];
        }
    }

    path1.pb(u);

    reverse(all(path2));

    for (auto x : path2)
        path1.pb(x);

    path1.pb(start); // complete cycle

    cout << path1.size() << endl;

    for (auto x : path1)
        cout << x << " ";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;  // cin >> tt;  // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++) {
        solve();
    }
    return 0;
}