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
#define Oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// gives order_of_key(x) -> returns no of elements < x and *find_by_order(x) -> value at x index

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
    let2(x, y);
    leta(a, x);
    leta(b, y);
    set<int> st(all(a));
    rep(i, y) st.insert(b[i]);
    
        vi v(all(st));
        sort(all(v), greater<>());
        int k = n + m - 1;
        int start = max(0LL, (long long)v.size() - k);

        long long ans = 0;

        for (int idx = start; idx < v.size(); idx++)
        {
            ans += v[idx];
        }
        cout << ans << "\n";
    
    // int i = x - 1;
    // int j = y - 1;
    // set<int> st;
    // while (i >= 0 and j >= 0) {
    //     if (m == 0 and n == 0) break;
    //     if (a[i] >= b[j] and n > 0 ) {
    //         if (st.count(a[i])) {
    //             i--;
    //         }
    //         else {

    //             if (st.empty()) {
    //                 st.insert(a[i]);
    //                 i--;
    //                 m--;
    //                 n--;
    //             } else {
    //                 st.insert(a[i]);
    //                 n--;
    //                 i--;
    //             }

    //         }

    //     } else if (a[i] < b[j] and m > 0) {
    //         if (st.count(b[j])) {
    //             j--;
    //         }
    //         else {

    //             if (st.empty()) {
    //                 st.insert(b[j]);
    //                 m--;
    //                 n--;
    //                 j--;
    //             } else {
    //                 st.insert(b[j]);
    //                 m--;
    //                 j--;
    //             }
    //         }
    //     }

    //     if (n == 0 and i >= 0) {
    //         a[i] = INT_MIN;
    //     }
    //     if (m == 0 and j >= 0) {
    //         b[j] = INT_MIN;
    //     }
    // }

    // while (m > 0) {
    //     if (j >= 0) {
    //         st.insert(b[j]);
    //         m--;
    //         j--;
    //     } else break;
    // }
    // while (n > 0) {
    //     if (i >= 0) {
    //         st.insert(a[i]);
    //         n--;
    //         i--;
    //     } else break;

    // }

    // cout << accumulate(all(st), 0LL) << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt; // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++)
    {
        solve();
    }
    return 0;
}