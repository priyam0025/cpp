#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<tuple<int,int,int>> customers;

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        customers.push_back({a, b, i});
    }

    sort(customers.begin(), customers.end());

    // min-heap: {departure, room_number}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    vector<int> ans(n);
    int room_count = 0;

    for(auto [a, b, idx] : customers) {
        if(!pq.empty() && pq.top().first < a) {
            // reuse room
            auto [dep, room] = pq.top();
            pq.pop();
            ans[idx] = room;
            pq.push({b, room});
        } else {
            // new room
            room_count++;
            ans[idx] = room_count;
            pq.push({b, room_count});
        }
    }

    cout << room_count << "\n";
    for(int x : ans) cout << x << " ";
}