#include <bits/stdc++.h>
using namespace std;

#define int long long
#define third_Sem_IT ios::sync_with_stdio(false); cin.tie(nullptr);

void run() {
    int a, b, c, d, e, f, g, h, i, j;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j ;
    double cgpa = (a * 2 + b * 2 + c * 3 + d * 0 + e * 2 + f * 2 + g * 3 + h * 2 + i * 3 + j * 2) / 21.0;
    cout << setprecision(3) << cgpa << '\n';
}

int32_t main() {
    third_Sem_IT
    // code by jeezus
    int tt = 1;
    // cin >> tt;
    while (tt--) run();
    return 0;
}