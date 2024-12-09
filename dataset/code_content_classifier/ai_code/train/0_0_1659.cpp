#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    vector<int> a(4), b(4);
    map<int, int> stones_a, stones_b;

    for(int i=0; i<4; i++) {
        cin >> a[i];
        stones_a[a[i]]++;
    }

    for(int i=0; i<4; i++) {
        cin >> b[i];
        stones_b[b[i]]++;
    }

    if(stones_a != stones_b) {
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int, int>> operations;
    for(int i=0; i<4; i++) {
        while(a[i] != b[i]) {
            int x = a[i];
            int y = b[i];

            if(x < y) {
                a[i] = 2*y - x;
            } else {
                a[i] = x - 2*(x-y);
            }

            operations.push_back({x, y});
        }
    }

    cout << operations.size() << endl;
    for(auto op : operations) {
        cout << op.first << " " << op.second << endl;
    }

    return 0;
}