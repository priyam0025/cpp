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

const int INF = 2e18;
const int mod = 998244353;

void solve() {
    let(n);

    string s;
    cin >> s;

    // repunit[i] = 111...111 (i times) modulo mod
    vector<int> repunit(n + 1);
    for (int i = 1; i <= n; i++) {
        repunit[i] = (repunit[i - 1] * 10 + 1) % mod;
    }

    // left = index of first non-zero digit
    int left = n;

    for (int i = 0; i < n; i++) {
        if (s[i] != '0') {
            left = i;
            break;
        }
    }

    let(q);

    while (q--) {
        let2(pos, num);

        // pos is counted from right
        int idx = n - pos;

        s[idx] = char('0' + num);

        // Update leftmost non-zero position
        if (num != 0 && idx < left) {
            left = idx;
        }

        // If we changed the current leftmost non-zero digit to zero,
        // find the next non-zero digit.
        if (idx == left && num == 0) {
            left = n;

            for (int i = idx + 1; i < n; i++) {
                if (s[i] != '0') {
                    left = i;
                    break;
                }
            }
        }

        // Number is 0
        if (left == n) {
            cout << 0 << endl;
            continue;
        }

        // Number of significant digits
        int d = n - left;

        // Number has only one digit
        if (d == 1) {
            cout << 0 << endl;
            continue;
        }

        // Last digit is non-zero
        if (s[n - 1] != '0') {
            cout << d - 1 << endl;
        }
        else {
            // Answer = 111...111 (d ones)
            cout << repunit[d] << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    while (tt--) {
        solve();
    }

    return 0;
}