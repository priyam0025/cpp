#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n, c; 
    cin >> n >> c;
    string s; cin >> s;
    int l = 0, r = 0, ans = INT_MIN;
    int cntA = 0, cntB = 0;
    int rude = 0;
    while (r < n) {
        if (s[r] == 'a') {
            cntA++;
        } else if (s[r] == 'b') {
            rude += cntA;
            cntB++;
        }
        while (rude > c) {
            if (s[l] == 'a') {
                cntA--;
                rude -= cntB;
            } else if (s[l] == 'b') {
                cntB--;
            }
            l++;
        }
        ans = max(ans, r - l + 1);
        r++;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    run();
    return 0;
}