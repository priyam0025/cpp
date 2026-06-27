#include <bits/stdc++.h>
using namespace std;

#define int long long

void run()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    cout << unique(v.begin(), v.end()) - v.begin();
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        run();
    return 0;
}