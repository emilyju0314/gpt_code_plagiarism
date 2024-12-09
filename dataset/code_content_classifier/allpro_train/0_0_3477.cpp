#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a;
    cin >> a;

    vector<int> main_tree(a);
    for (int i = 0; i < a - 1; i++) {
        cin >> main_tree[i];
    }

    vector<int> main_devices(n);
    for (int i = 0; i < n; i++) {
        cin >> main_devices[i];
    }

    int b;
    cin >> b;

    vector<int> reserve_tree(b);
    for (int i = 0; i < b - 1; i++) {
        cin >> reserve_tree[i];
    }

    vector<int> reserve_devices(n);
    for (int i = 0; i < n; i++) {
        cin >> reserve_devices[i];
    }

    int moves = 0;

    // Iterate through each device and calculate the moves needed to power it from both grids
    for (int i = 0; i < n; i++) {
        int main_path_length = 0;
        int main_position = main_devices[i];

        while (main_position != 1) {
            main_path_length++;
            main_position = main_tree[main_position - 2];
        }

        int reserve_path_length = 0;
        int reserve_position = reserve_devices[i];

        while (reserve_position != 1) {
            reserve_path_length++;
            reserve_position = reserve_tree[reserve_position - 2];
        }

        moves += min(main_path_length, reserve_path_length);
    }

    cout << moves << endl;

    return 0;
}