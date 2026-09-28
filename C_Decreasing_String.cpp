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
    string s;
    cin >> s;
    // if (sz(s) == 1) {
    //     cout << s;
    //     return;
    // }
    string copy = s;
    let(pos);
    if (sz(s) >= pos)
    {
        cout << s[pos - 1];
        return;
    }
    // queue<string> q;

    for (int i = 0; i + 1 < sz(copy);)
    {
        if (copy[i] > copy[i + 1])
        {
            int k = i;
            bool f = false;
            while (k > 0 and copy[k] == copy[k - 1])
            {
                if (!f)
                    f = true;
                // string tmp = copy.substr(0, k) + copy.substr(k + 1);
                s += copy.substr(0, k) + copy.substr(k + 1);
                if (sz(s) >= pos)
                {
                    cout << s[pos - 1];
                    return;
                }
                copy = copy.substr(0, k) + copy.substr(k + 1);
                k--;
            }
            if (f)
            {
                i = k;
                continue;
            }
            // string tmp = copy.substr(0, i) + copy.substr(i + 1);
            s += copy.substr(0, i) + copy.substr(i + 1);
            if (sz(s) >= pos)
            {
                cout << s[pos - 1];
                return;
            }
            copy = copy.substr(0, i) + copy.substr(i + 1);
            i--;
        }
        else
            i++;
    }

    for (int i = copy.size() - 1; i >= 0; --i)
    {
        s += copy.substr(0, i);
        if (sz(s) >= pos)
        {
            cout << s[pos - 1];
            return;
        }
    }

    // while (!q.empty())
    // {
    //     s += q.front();
    //     q.pop();
    // }
    //  cout << s << "\n";
    cout << s[pos - 1];
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