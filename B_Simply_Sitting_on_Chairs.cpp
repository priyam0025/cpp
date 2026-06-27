#include <bits/stdc++.h>
using namespace std;

#define int long long

void run()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    vector<bool> marked(n + 1, false);
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (marked[i])
        {
            cout << cnt << '\n';
            return;
        }
        if (p[i - 1] <= i)
        {
            marked[p[i - 1]] = true;
            cnt++;
        }
        else continue;
    }
    cout << cnt << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        run();
    return 0;
}