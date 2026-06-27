#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")

#define endl '\n'
#define vi vector<long long>
#define vvi vector<vector<long long>>
#define vpii vector<pair<long long, long long>>
#define pb push_back
#define pii pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define sz(x) (long long)(x).size()
#define fi first
#define se second
#define rep(i, n) for(long long i = 0; i < n; i++)
#define rep1(i, n) for(long long i = 1; i <= n; i++)
#define FOR(i, a, b) for(long long i = a; i < b; i++)
#define maxel(x) (*max_element(all(x)))
#define minel(x) (*min_element(all(x)))
#define let(n) long long n; cin >> n;
#define let2(a, b) long long a, b; cin >> a >> b;
#define leta(arr, n) vi arr(n); for(long long i = 0; i < n; i++) cin >> arr[i];
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define print(x) cout << x << endl

const long long INF = 2e18;
const long long mod = 1e9 + 7;

long long ipow(long long x, long long y) {
    long long res = 1;
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


long long binSearch(const vi &pmax, long long val)
{
    long long low = 0, high = sz(pmax) - 1;
    long long ans = -1;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        if (pmax[mid] <= val)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

void solve()
{
    let2(n, q);

    vi steps(n), query(q);

    rep(i, n) cin >> steps[i];
    rep(i, q) cin >> query[i];

    vi pmax(n), psum(n);

    pmax[0] = steps[0];
    psum[0] = steps[0];

    for (long long i = 1; i < n; i++)
    {
        pmax[i] = max(pmax[i - 1], steps[i]);
        psum[i] = psum[i - 1] + steps[i];
    }

    for (long long i = 0; i < q; i++)
    {
        long long val = query[i];
        long long ind = binSearch(pmax, val);

        if (ind == -1)
            cout << 0 << " ";
        else
            cout << psum[ind] << " ";
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long tt;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
