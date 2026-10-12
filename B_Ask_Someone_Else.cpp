#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU {
    vector<int> par;

    DSU(int n) { par.assign(n + 1, -1); }

    int root(int v) { return par[v] < 0 ? v : par[v] = root(par[v]); }

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int v) { return -par[root(v)]; }

    bool same(int x, int y) { return root(x) == root(y); }
};

bool checkOne(vector<int>& a) {
    int n = a.size() - 1;

    int u = a[1];

    for (int i = 0; i < n; i++) {
        if (u == 1)
            return true;

        u = a[u];
    }

    return false;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        DSU dsu(n);

        if (checkOne(a)) {
            dsu.merge(1, a[1]);
        }

        for (int i = 2; i <= n; i++) {
            dsu.merge(i, a[i]);
        }

        int ans = 0;
        vector<int> other;

        for (int i = 1; i <= n; i++) {
            if (i != dsu.root(i))
                continue;

            if (dsu.same(i, 1)) {
                ans += dsu.size(i);
            } else {
                other.push_back(dsu.size(i));
            }
        }

        sort(other.begin(), other.end(), greater<int>());

        int take = min(k, (int)other.size());

        for (int i = 0; i < take; i++) {
            ans += other[i];
        }

        cout << ans << '\n';
    }

    return 0;
}