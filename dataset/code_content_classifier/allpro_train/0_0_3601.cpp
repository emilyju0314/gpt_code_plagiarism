#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> columns(n);
    int total_left = 0, total_right = 0, initial_beauty = 0, max_beauty = 0, max_index = 0;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        columns[i] = make_pair(l, r);
        total_left += l;
        total_right += r;
    }

    initial_beauty = abs(total_left - total_right);

    for (int i = 0; i < n; i++) {
        int new_beauty = abs((total_left - columns[i].first + columns[i].second) - (total_right - columns[i].second + columns[i].first));
        if (new_beauty > max_beauty) {
            max_index = i + 1;
            max_beauty = new_beauty;
        }
    }

    if (max_beauty > initial_beauty) {
        cout << max_index << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}