// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// void run() {
//     int n, s;
//     cin >> n >> s;
//     vector<int> a(n);
//     for (int i = 0; i < n; ++i) cin >> a[i];
//     auto bro = [&](vector<int> a, int x) -> int {
//         int l = 0, r = 0;
//         int sum = 0;
//         int cnt = 0;
//         while (r < a.size()) {
//             sum += a[r];
//             while (sum >= x) {
//                 cnt += (n - r);
//                 sum -= a[l];
//                 l++;
//             }
//             r++;
//         }
//         return cnt;
//     };
//     int ans = bro(a, s);
//     cout << ans << '\n';
// }

// int32_t main() {
//     ios::sync_with_stdio(false); cin.tie(nullptr);
//     int tt = 1;
//     // cin >> tt;
//     while (tt--) run();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, s;
    cin >> n >> s;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int r = 0;
    int l = 0;
    long long sum = 0;
    long long count = 0;
    while (r < nums.size())
    {
        sum += nums[r];
        while (sum >= s)
        {
            sum -= nums[l];
            l++;
        }
        count += (r - l + 1);
        r++;
    }
    long long total_sub_arrays = n * (n + 1) / 2;
    long long result = total_sub_arrays - count;
    cout << result;
    return 0;
}