#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define Oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// gives order_of_key(x) -> returns no of elements < x and *find_by_order(x) -> value at x index

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

void findPairs(int n, vector<vector<pii>>& adj) {
    int bits = 0;
    while ((1LL << bits) <= n) bits++;

    int fullMask = (1LL << bits) - 1;

    for (int i = 1; i <= n; i++) {
        int mask = (~i) & fullMask;

        for (int j = mask; j > 0; j = (j - 1) & mask) {
            if (j <= n && i < j) {
                adj[i].pb({i + j, j});
                adj[j].pb({i + j, i});
            }
        }
    }
}

void solve() {
    let2(n, q);
    vector<vector<pii>> adj(n + 1);
    findPairs(n, adj);
    // vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));
    // rep1(i, n) {
    //     for (int j = i + 1; j < n + 1; ++j) {
    //         if (((i & j) == 0) && !vis[i][j] && !vis[j][i]) {
    //             adj[i].pb({i + j, j});
    //             adj[j].pb({i + j, i});
    //             vis[i][j] = true;
    //             vis[j][i] = true;
    //         }
    //     }
    // }

    auto djk = [&](int src) -> vi {
        vi dist(n + 1, INF);
        priority_queue<pii, vpii, greater<pii>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, node] = pq.top(); pq.pop();
            if (d > dist[node]) continue;
            for (auto &[wt, nxt] : adj[node]) {
                if (wt + d < dist[nxt]) {
                    dist[nxt] = wt + d;
                    pq.push({wt + d, nxt});
                }
            }
        }
        return dist;
    };
    
    while (q--) {
        let2(s, t);
        if (s == t) {
            cout << 0 << "\n";
            continue;
        }
        vi ans = djk(s);
        //  printa(ans);
        if (ans[t] != INF) {
            cout << ans[t] << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;  // cin >> tt;  // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++) {
        solve();
    }
    return 0;
}