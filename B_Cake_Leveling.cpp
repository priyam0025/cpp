#include <bits/stdc++.h>
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t = 1;
	cin >> t;
    while(t-->0)
    {
        int n;
        cin >> n;

        vll a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        ll ans = 1e9, sum = 0;

        for(int i=0; i<n; i++)
        {
            sum += a[i];
            ans = min(ans, sum / (i + 1));

            cout << ans << " ";
        }

        cout << "\n";
    }
}