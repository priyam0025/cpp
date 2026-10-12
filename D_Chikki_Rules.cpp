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
    let(n);
    leta(a, n);
    leta(b, n);
    sort(all(a), greater<int>());
    sort(all(b), greater<int>());
    int tot1 = accumulate(all(a), 0LL);
    int tot2 = accumulate(all(b), 0LL);
    int c = 0;
    int op = 0;
    
    for (int i = 0; i < n; ++i) {

        if (a[i] + c < b[i]) {
            cout << -1 << "\n";
            return;
        }
        if (a[i] >= b[i]) {
            c += (a[i] - b[i]);
            op += (a[i] - b[i]);
            a[i] = b[i];
        } else if (a[i] < b[i]) {
            int d = b[i] - a[i];
            c -= d;
            a[i] = a[i] + d;
        } 
    }
    if (tot1 == tot2)
    cout << op << "\n";
    else cout << -1 << "\n";
    // int i = 0, j = n - 1;
    // while (i < j) {
    //     while (a[i] == b[i]) i++;
    //     while (a[j] == b[j]) j--;

    //     while (a[i] > b[i]) {
    //         a[i]--;
    //         b[j]++;
    //     }

    // }
    // if (n == 1 and a[0] == b[0]) {
    //     cout << 0 << "\n";
    //     return;
    // } 
    // int i =0;
    // while (a[i] == b[i]) i++;
    // if (a[i] < b[i]) {
    //     cout << -1 << "\n";
    //     return;
    // }

    // int plus = 0, minus = 0;
    // for (int i = 0; i < n; ++i) {
    //     if (a[i] == b[i]) continue;
    //     else if (a[i] > b[i]) {
    //         plus += (a[i] - b[i]);
    //     } else {
    //         minus += (b[i] - a[i]);
    //     }
    // }
    // // cout << plus << " " << minus << "\n";
    // if (plus == minus) {
    //     cout << plus << "\n";
    // } else {
    //     cout << -1 << "\n";
    // }
    
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;   cin >> tt;  // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++) {
        solve();
    }
    return 0;
}