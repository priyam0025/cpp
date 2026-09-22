#include <bits/stdc++.h>
using namespace std;

#define int long long

void run(int n) {
    vector<pair<int, int>> v, v0;
    // int mini = INT_MAX;
    // int gem = 0;
    // for (int i = 0; i < n; ++i) {
    //     int a, b; cin >> a >> b;

    //     if (b != 0) {
    //         mini = min(mini, a);
    //         gem += b;
    //         v.push_back({a, b});
    //     }
            
    //     else v0.push_back({a, b});
    // }
    // // sort(v.begin(), v.end());
    // gem -= v.size() - 1;
    // if (v.size() == 0) {
    //     mini = 0; gem = 0;
    // }
    // sort(v0.rbegin(), v0.rend());
    // int ans = mini;
    
    // for (int i = gem; i < v0.size(); ++i) {
    //     ans += v0[i].first;
    // }
    // cout << ans << "\n";
    int sum =0 ;
    int nonz = 0;
    int mini =INT_MAX;
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        if (b != 0) {
            nonz++;
            mini = min(mini, a);
            sum += b;
        }
        v.push_back({a,b});
    }
    sort(v.rbegin(), v.rend());
    int gem = sum - (nonz - 1);
    int ans = mini;
    for (int i = gem; i < n; ++i) {
        ans += v[i].first;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while(true) {
        int n;
        cin  >> n;
        if (n == 0) break;
        else run(n);
    }
    return 0;
}