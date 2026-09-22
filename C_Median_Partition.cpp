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

    vector<int> a(n);
    map<int, int> freq;

    for (int &x : a) {
        cin >> x;
        freq[x]++;
    }

    // Element having maximum frequency initially
    int mxFreq = 0;
    int element = -1;
    int mxCount = 0;

    for (auto &[x, f] : freq) {
        if (f > mxFreq) {
            mxFreq = f;
            element = x;
            mxCount = 1;
        }
        else if (f == mxFreq) {
            mxCount++;
        }
    }

    // If multiple elements have the same maximum frequency
    if (mxCount > 1) {
        cout << 1 << '\n';
        return ;
    }

    int i = 0, j = 0;
    int cnt = 0;

    while (j < n) {

        int len = j - i + 1;

        // Only odd-sized windows
        if (len % 2 == 1) {

            vector<int> temp(a.begin() + i, a.begin() + j + 1);
            sort(temp.begin(), temp.end());

            int median = temp[len / 2];

            if (median == element) {
                cnt++;

                // Start next window
                i = j + 1;
                j = i;
                continue;
            }
        }

        j++;
    }

    cout << cnt << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;   cin >> tt;  // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++) {
        solve();
    }
    return 0;
}