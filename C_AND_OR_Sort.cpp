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
    int n;
    cin >> n;
    string s;
    cin >> s;

    // 1. Check if already sorted
    if (is_sorted(s.begin(), s.end())) {
        cout << 0 << "\n";
        return;
    }

    // Count total zeros in the string
    int total_zeros = 0;
    for (char c : s) {
        if (c == '0') total_zeros++;
    }

    // 2. If s[0] == '1', we can only turn all elements into '1'
    if (s[0] == '1') {
        cout << total_zeros << "\n";
        return;
    }

    // 3. If s[0] == '0', find the optimal split point k
    int pref_ones = 0;
    int suf_zeros = total_zeros;
    
    // Initial best option: k = 0 (all 1s, but s[0] is 0 so k must be at least 1)
    int min_ops = n; 

    for (int k = 0; k < n; k++) {
        if (s[k] == '1') {
            pref_ones++;
        } else {
            suf_zeros--;
        }
        // Operations needed if prefix s[0...k] becomes 0s and suffix s[k+1...n-1] becomes 1s
        min_ops = min(min_ops, pref_ones + suf_zeros);
    }

    cout << min_ops << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;  cin >> tt;  // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++) {
        solve();
    }
    return 0;
}