#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int test = 0; test < t; test++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<long long> a(3, 0);
        a[0] = 1;
        long long x = 0;
        long long ans = 0;
        char pre = '2';
        long long y = 0;
        for(char c : s) {
            if(c == '0') x -= 1;
            else x += 1;
            x %= 3;
            if(x < 0) x += 3;
            if(c == pre) {
                y = 1;
            } else {
                y += 1;
            }
            pre = c;
            ans += (a[0] + a[1] + a[2]) - a[x];
            a[x] += 1;
            ans -= (y - 1) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}