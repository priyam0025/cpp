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

void solve() {
    let3(a, b, c);
    int n = a + b + c;
    if(c > a && (c - a) % 3 != 0) {
        cout << -1 << "\n";
        return;
    }
    if (b & 1) {
        cout << -1 << "\n";
        return;
    }
    // vector<bool> vis(2 * (a + b  +c) + 1, false);
    int i = 1;
    while (b > 0) {
        // if (!vis[i] and !vis[i + 2])
            cout << i << " " << i + 2 << "\n";
            cout << i + 1 << " " << i + 3 << "\n";
        // vis[i] = true;
        // vis[i + 2] = true;
        i += 4;
        b-= 2;
    }
    int f = min(a, c);
    int common = f;
    while(f > 0 and i + 3 <= 2 * n) {
        
                cout << i << " " << i + 3 << "\n";
                cout << i + 1 << " " << i + 2 << "\n";
                

                // vis[i] = true;
                // vis[i + 3] = true;
                f--;
            
        // if (!vis[i + 1] and !vis[i + 2]) {
        //     cout << i + 1 << ' ' << i + 2 << "\n";
        //     vis[i + 1] = true;
        //     vis[i + 2] = true;
        // }
        
        i+= 4;
        
    }
    a -= common;
    c -= common;
    while (a > 0 and i + 1 <= 2 * n) {
            cout << i << " " << i + 1 << "\n";
            i+=2;
            // vis[i] = true;
            // vis[i + 1] = true;
            a--;
    }
    while (c > 0 and i + 5 <= 2 * n) {
            cout << i << " " << i + 3 << "\n";
            cout << i + 1 << " " << i + 4 << "\n";
            cout << i + 2 << " " << i + 5 << "\n";
            i += 6;
            c -= 3;
            // vis[i] = true;
            // vis[i + 3] = true;
            // c--;
        
        // i++;
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;   cin >> tt;  // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++) {
        solve();
    }
    return 0;
}