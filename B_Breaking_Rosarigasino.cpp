#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    // getline(cin, s);
    // // trim possible trailing whitespace/newline
    // while (!s.empty() && (s.back() == '\n' || s.back() == '\r' || s.back() == ' '))
    //     s.pop_back();

    int n = s.size();
    string vowels = "AEIOU";
    set<string> cands;

    for (int i = 0; i + 2 < n; i++) {
        if (s[i] == 'G' && s[i+1] == 'A' && s[i+2] == 'S') {
            if (i - 1 >= 0 && i + 3 < n) {
                if (s[i-1] == s[i+3] && vowels.find(s[i-1]) != string::npos) {
                    string cand = s.substr(0, i) + s.substr(i + 4);
                    cands.insert(cand);
                }
            }
        }
    }

    if (cands.empty()) {
        cout << "-" << endl;
    } else if (cands.size() == 1) {
        cout << *cands.begin() << endl;
    } else {
        cout << "+" << endl;
    }

    return 0;
}