#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")

#define int long long
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pb push_back
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i <= n; i++)
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define maxel(x) (*max_element(all(x)))
#define minel(x) (*min_element(all(x)))
#define let(n) int n; cin >> n;
#define let2(a, b) int a, b; cin >> a >> b;
#define let3(a, b, c) int a, b, c; cin >> a >> b >> c;
#define leta(arr, n) vi arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define print(...) cout << __VA_ARGS__ << endl
#define YN(f) cout << (f ? "YES" : "NO") << endl

const int INF = 2e18;
const int mod = 1e9 + 7;
const int mod2 = 998244353;

int ipow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

void printa(const vi &a) {
    for (auto x : a) cout << x << ' ';
    cout << endl;
}

void solve() {
    let2(n, w);
    leta(a, n);
    //map<int, int> mp; //widthCount <logval, cnt>
    vector<int> mp(21, 0);
    rep(i, n) {
        int logVal = log2(a[i]);
        mp[logVal]++;
    }
    int h = 0;
    int used = 0;
    while (used < n) {
        int tmp = w;
        for (int i = 20; i >= 0; --i) {
            if (mp[i] > 0 and (1 << i) <= tmp) {
                tmp -= (1 << i);
                mp[i]--;
                used++;
            }
        }
        h++;
    }
    cout << h << "\n";
}

// int32_t main() {
//     ios::sync_with_stdio(false); cin.tie(nullptr);
//     int tt = 1;  cin >> tt;  // Uncomment for multiple test cases
//     for (int t = 1; t <= tt; t++) {
//         solve();
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int t; 
// 	cin >> t; // Read the number of test cases
// 	while (t--) {
// 		int n, w; 
// 		cin >> n >> w; // Read the number of rectangles and the width of the box for each test case
// 		vector<int> a(n);
// 		for (int i = 0; i < n; i++) { // O(n)
// 			cin >> a[i]; // Read the width of each rectangle
// 		}
// 		vector<int> widthCount(21, 0); // Initialize a vector to count the occurrences of each power of 2 width
// 		for (int i = 0; i < n; i++) { // O(n * log(a[i]))
// 			int logVal = log2(a[i]); // Calculate the power of 2 for the current rectangle width
// 			widthCount[logVal]++; // Increment the count for this power of 2
// 		}
// 		int height = 0; // Initialize the height of the box
// 		int countOfUsedBoxes = 0; // Initialize the count of rectangles that have been placed in the box
// 		while (countOfUsedBoxes < n) { // O(n * log(a[i]))
// 			int temp = w; // Start with the full width of the box
// 			for (int i = 20; i >= 0; i--) { // Check from the largest power of 2 to the smallest
// 				while (widthCount[i] > 0 && (1 << i) <= temp) { // While there are rectangles of this width and they fit in the remaining width
// 					temp -= (1 << i); // Reduce the remaining width by the width of the rectangle
// 					widthCount[i]--; // Decrease the count of this width
// 					countOfUsedBoxes++; // Increase the count of used rectangles
// 				}
// 			}
// 			height++; // Increase the height of the box as a new row is used
// 		}
// 		cout << height << endl; // Output the minimum height of the box for the current test case
// 	}
// }

// // Time Complexity (TC): O(n * log(a[i]))
// // Space Complexity (SC): O(n)
