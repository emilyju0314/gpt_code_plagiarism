#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<pair<int, int>> friends;
    for(int i = 0; i < n; i++){
        friends.push_back({t[i], i});
    }
    sort(friends.begin(), friends.end(), greater<pair<int,int>>());

    vector<bool> online(n, false);
    vector<int> order;
    for(int i = 0; i < q; i++) {
        int type, id;
        cin >> type >> id;
        id--;

        if(type == 1) {
            online[id] = true;
            order.push_back(id);
        } else {
            bool displayed = false;
            for(int j = 0; j < min(k, (int)order.size()); j++) {
                if(order[j] == id) {
                    displayed = true;
                    break;
                }
            }
            if(displayed) {
                cout << "YES" << endl;
            } else {
                if(order.size() < k || friends[id].first > friends[order[k-1]].first) {
                    cout << "NO" << endl;
                } else {
                    cout << "YES" << endl;
                }
            }
        }
    }

    return 0;
}