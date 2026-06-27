#include <bits/stdc++.h>
using namespace std;

#define int long long

void run() {
    int n ; cin >> n;
    
    vector<int> a(n) ;
    
    for(int i = 0 ; i < n; i++) {
        cin >> a[i] ;
    }
 
    int sum = a[0], mn = a[0] ;
 
    for(int i = 1; i < n; i++) {
        mn = min(a[i], mn) ;
        sum += mn ;
    }
    cout << sum << "\n" ;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) run();
    return 0;
}