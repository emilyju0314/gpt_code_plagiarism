#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int q;
    cin >> q;

    vector<int> arr;
    unordered_map<int, int> replace_map;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            arr.push_back(x);
        } else {
            int x, y;
            cin >> x >> y;
            replace_map[x] = y;
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        if (replace_map.find(arr[i]) != replace_map.end()) {
            arr[i] = replace_map[arr[i]];
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}