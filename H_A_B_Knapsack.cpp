#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, m, s, A, B;
    cin >> n >> m >> s >> A >> B;

    vector<int> a(n), b(m);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    vector<int> prefA(n + 1, 0), prefB(m + 1, 0);
    for (int i = 0; i < n; i++)
        prefA[i + 1] = prefA[i] + a[i];
    for (int i = 0; i < m; i++)
        prefB[i + 1] = prefB[i] + b[i];

    int ans = 0;
    for (int x = 0; x <= n; x++) {
        int weightA = x * A;
        if (weightA > s) break;

        int remaining = s - weightA;

        int y = min(m, remaining / B);

        ans = max(ans, prefA[x] + prefB[y]);
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
}