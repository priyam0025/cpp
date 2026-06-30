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
    let(x);
    vi goodNums;
    
    auto get = [&](int m) -> bool
    {
        string s = to_string(m);
        set<char> st(all(s));
        return sz(st) <= 2;
    };

    auto generate = [&]() -> void //taken
    {
        set<int> st;

        for (char d = '0'; d <= '9'; d++)
        {
            if (d == '0')
                continue;
            string cur;
            for (int len = 1; len <= 10; len++)
            {
                cur += d;
                int x = stoll(cur);
                if (x <= 100000000LL)
                    st.insert(x);
            }
        }

        for (char d1 = '0'; d1 <= '9'; d1++)
        {
            for (char d2 = d1 + 1; d2 <= '9'; d2++)
            {

                for (int len = 1; len <= 10; len++)
                {

                    int total = 1 << len;

                    for (int mask = 0; mask < total; mask++)
                    {

                        string s(len, d1);
                        for (int i = 0; i < len; i++)
                            if (mask & (1 << i))
                                s[i] = d2;

                        if (s[0] == '0')
                            continue;

                        int x = stoll(s);
                        if (x <= 1000000000LL)
                            st.insert(x);
                    }
                }
            }
        }

        goodNums.assign(st.begin(), st.end());
    };
    generate();
    for (int y : goodNums)
    {
        if (y < 2)
            continue;
        if (get(x * y))
        {
            cout << y << '\n';
            return;
        }
    }
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