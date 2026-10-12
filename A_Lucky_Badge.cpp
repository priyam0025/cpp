#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s; 
        cin >> s;

        string v = "";
        string con = "";
        vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        map<char, int> mp;

        auto pal = [&](string s) -> bool {
            int i = 0, j = s.size() -1;
            while (i < j) {
                if (s[i] != s[j]) return false;
                i++;
                j--;
            }
            return true;
        };

        for (auto c : s) {
            if (find(vowel.begin(), vowel.end(),c) != vowel.end()) v += c;
            else con += c;
            mp[c]++;
        }
        int cnt = 0;
        for (auto [c, x] : mp) {
            if (x & 1) cnt++;
        }

        int vn = v.size();
        int conn = con.size();
        if ((vn & 1) and (conn & 1)) {
            cout << "NO" << "\n";
            continue;
        }
        
        if (pal(v) and pal(con)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
        // if (cnt > 1) {
        //     cout << "NO" << "\n";
        // } 
    }
    return 0;
}