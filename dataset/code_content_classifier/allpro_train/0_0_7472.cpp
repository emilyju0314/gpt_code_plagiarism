#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<int> empty_spaces;
    for (int i = 1; i <= n; i++) {
        empty_spaces.insert(i);
    }

    vector<int> parking_lot(2e5 + 1, -1);

    for (int i = 0; i < m; i++) {
        int type, car_id;
        cin >> type >> car_id;

        if (type == 1) {
            if (empty_spaces.empty()) {
                cout << -1 << endl;
            } else {
                int empty_space = *empty_spaces.begin();
                cout << empty_space << endl;

                parking_lot[car_id] = empty_space;
                empty_spaces.erase(empty_space);
            }
        } else {
            int empty_space = parking_lot[car_id];
            empty_spaces.insert(empty_space);
            parking_lot[car_id] = -1;
        }
    }

    return 0;
}