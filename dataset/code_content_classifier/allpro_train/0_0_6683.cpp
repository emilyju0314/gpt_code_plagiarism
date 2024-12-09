#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        unordered_map<int, int> room_map;
        bool valid = true;

        for (int k = 0; k < n; k++) {
            int target_room = (k + a[k % n] + n) % n;
            if (room_map.find(target_room) != room_map.end() || target_room < 0) {
                valid = false;
                break;
            }
            room_map[target_room] = 1;
        }

        if (valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}