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
    let2(n, m);
    vector<string> grid(n);
    rep(i, n) cin >> grid[i];
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vpii> parent(n, vpii(m));

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    int sx = 0, sy = 0, fx = 0, fy = 0;

    rep (i, n) {
        rep (j , m) {
            if (grid[i][j] == 'A') {
                sx = i; sy = j;
            }
            else if (grid[i][j] == 'B') {
                fx = i, fy = j;
            }
        }
    }
    
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' 
            && !visited[nx][ny]) {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            } 
        }
    }
    if (!visited[fx][fy]) {
        NO;
        return;
    }
    YES;

    string path;
    int x = fx, y = fy;
    while (x != sx || y != sy) {
        auto [px, py] = parent[x][y];
        if (x == px + 1) path  += 'D';
        else if (x == px - 1) path += 'U';
        else if (y == py + 1) path += 'R';
        else if (y == py - 1) path += 'L';
        x = px;
        y = py;
    }

    reverse(all(path));

    cout << sz(path) << "\n";
    cout << path << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;  // cin >> tt;  // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++) {
        solve();
    }
    return 0;
}