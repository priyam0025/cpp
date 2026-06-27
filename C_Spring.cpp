#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int a, b, c, m;
    cin >> a >> b >> c >> m; 

    int na = m / a;
    int nb = m / b;
    int nc = m / c;

    int lab = lcm(a, b);
    int lbc = lcm(b, c);
    int lca = lcm(c, a);
    int labc = lcm(lab, c);

    int nab = m / lab;
    int nbc = m / lbc;
    int nca = m / lca;
    int nabc = m / labc;

    int q1 = (na - nab - nca + nabc) * 6 + (nab - nabc + nca - nabc) * 3 + (nabc) * 2;
    int q2 = (nb - nab - nbc + nabc) * 6 + (nab - nabc + nbc - nabc) * 3 + (nabc) * 2;
    int q3 = (nc - nca - nbc + nabc) * 6 + (nca - nabc + nbc - nabc) * 3 + (nabc) * 2;

    cout << q1 << " " << q2 << " " << q3 << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) run();
    return 0;
}