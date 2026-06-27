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
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define maxel(x) (*max_element(all(x)))
#define minel(x) (*min_element(all(x)))
#define let(n) \
    int n;     \
    cin >> n;
#define let2(a, b) \
    int a, b;      \
    cin >> a >> b;
#define let3(a, b, c) \
    int a, b, c;      \
    cin >> a >> b >> c;
#define leta(arr, n)            \
    vi arr(n);                  \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define print(...) cout << __VA_ARGS__ << endl
#define YN(f) cout << (f ? "YES" : "NO") << endl

const int INF = 2e18;
const int mod = 1e9 + 7;
const int mod2 = 998244353;

int ipow(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

void printa(const vi &a)
{
    for (auto x : a)
        cout << x << ' ';
    cout << endl;
}

void solve()
{
    let2(n, m);
    vector<int> path(n + 1);
    vector<int> dist(n + 1, 1e18);
    priority_queue<pii, vpii, greater<pii>> pq;
    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        let3(x, y, w);
        adj[x].push_back({w, y});
        adj[y].push_back({w, x});
    }
    pq.push({0, 1});
    path[1] = 1;
    dist[1] = 0;
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int d = top.fi;
        int u = top.se;

        for (auto p : adj[u])
        {
            int w = p.fi;
            int v = p.se;
            if (w + dist[u] < dist[v])
            {
                dist[v] = w + dist[u];
                pq.push({w + dist[u], v});
                path[v] = u;
            }
        }
    }
    if (dist[n] == 1e18) {
        cout << -1 << '\n';
        return ;
    }
    vector<int> res;
    int node = n;
    while (node != path[node])
    {
        res.push_back(node);
        node = path[node];
    }
    reverse(all(res));
    cout << 1 << ' ';
    printa(res);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; // cin >> tt;  // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++)
    {
        solve();
    }
    return 0;
}