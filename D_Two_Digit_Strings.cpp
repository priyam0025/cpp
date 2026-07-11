#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

void upd(int& x, int y)
{
    if(x < y) x = y;
}

void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<int> ps(n + 1), pt(m + 1);
    for(int i = 0; i < n; i++)
        ps[i + 1] = (ps[i] + (s[i] - '0')) % 10;
    for(int i = 0; i < m; i++)
        pt[i + 1] = (pt[i] + (t[i] - '0')) % 10;
    n++;
    m++;
    if(ps.back() != pt.back())
    {
        cout << -1 << "\n";
        return;
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
        {
            if(i < n) upd(dp[i + 1][j], dp[i][j]);
            if(j < m) upd(dp[i][j + 1], dp[i][j]);
            if(i < n && j < m && ps[i] == pt[j]) upd(dp[i + 1][j + 1], dp[i][j] + 1);
        }
    cout << dp[n][m] - 1 << "\n";
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        solve();
    return 0;
}