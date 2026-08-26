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

int a[200000];
int pre[31][200001];

void solve() {
    let(n);
    rep (i, n) {
        cin >> a[i];
    }

    rep(j, 31) {
        pre[j][0] = 0; //empty prefix has 0 zero
        rep(i, n) {
            if (a[i] & (1LL << j)) {
                pre[j][i + 1] = pre[j][i]; 
            } else {
                pre[j][i + 1] = pre[j][i] + 1;
            }
        }
    }

    auto range_and = [&](int l, int r) -> int {
        int ans = 0;
        rep(i, 30) {
            if (pre[i][r + 1] - pre[i][l] == 0) {
                ans += (1 << i);
            }
        }
        return ans;
    };

    let(q);
    while(q--) {
        let2(l, k);
        l--;
        // AND over an expanding range is non-increasing; if a[l] < k, no r can satisfy.
		if (a[l] < k) {
			cout << -1 << ' ';
			continue;
		}
        int lo = l, hi = n - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (range_and(l, mid) >= k) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        cout << lo + 1 << " ";
    }
    cout << "\n";

}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;   cin >> tt;  // Uncomment for multiple test cases
    for (int t = 1; t <= tt; t++) {
        solve();
    }
    return 0;
}