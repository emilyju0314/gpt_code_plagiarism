#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> balances(n);
    for(int i = 0; i < n; i++) {
        cin >> balances[i];
    }

    int q;
    cin >> q;

    vector<pair<int, int>> events;
    for(int i = 0; i < q; i++) {
        int type, p, x;
        cin >> type;
        if(type == 1) {
            cin >> p >> x;
            p--; // 0-based indexing
            events.push_back({type, p});
            balances[p] = x;
        } else {
            cin >> x;
            events.push_back({type, x});
        }
    }

    int maxPayout = 0;
    for(auto event : events) {
        if(event.first == 2) {
            maxPayout = max(maxPayout, event.second);
        }
    }

    for(auto event : events) {
        if(event.first == 2) {
            maxPayout = event.second;
        } else {
            balances[event.second] = max(balances[event.second], maxPayout);
        }
    }

    for(int i = 0; i < n; i++) {
        cout << balances[i] << " ";
    }

    return 0;
}