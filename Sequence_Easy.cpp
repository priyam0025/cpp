#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> fact(N + 1, 1);
        for (int i = 1; i <= N; i++)
            fact[i] = fact[i - 1] * i % MOD;

        vector<vector<long long>> dp(K, vector<long long>(N + 1, 0));
        dp[0][0] = 1;

        for (int pos = 1; pos <= N; pos++) {
            vector<vector<long long>> ndp(K, vector<long long>(N + 1, 0));

            // Don't take current element
            for (int run = 0; run < K; run++) {
                for (int cnt = 0; cnt <= N; cnt++) {
                    ndp[0][cnt] += dp[run][cnt];
                    if (ndp[0][cnt] >= MOD) ndp[0][cnt] -= MOD;
                }
            }

            // Take current element
            for (int run = 0; run < K - 1; run++) {
                for (int cnt = 0; cnt < N; cnt++) {
                    ndp[run + 1][cnt + 1] += dp[run][cnt];
                    if (ndp[run + 1][cnt + 1] >= MOD)
                        ndp[run + 1][cnt + 1] -= MOD;
                }
            }

            dp.swap(ndp);
        }

        vector<long long> bad(N + 1, 0);
        for (int run = 0; run < K; run++) {
            for (int cnt = 0; cnt <= N; cnt++) {
                bad[cnt] += dp[run][cnt];
                bad[cnt] %= MOD;
            }
        }

        long long ans = 0;
        for (int m = 0; m < N; m++) {
            ans = (ans + bad[m] * fact[m] % MOD * fact[N - m]) % MOD;
        }

        cout << ans % MOD << '\n';
    }

    return 0;
}