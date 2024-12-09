#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string rooms;
    cin >> rooms;

    vector<int> cow_positions;
    for (int i = 0; i < n; i++) {
        if (rooms[i] == '0') {
            cow_positions.push_back(i);
        }
    }

    int min_distance = INT_MAX;
    for (int i = 0; i <= cow_positions.size() - k; i++) {
        int distance = cow_positions[i+k] - cow_positions[i];
        min_distance = min(min_distance, distance);
    }

    cout << min_distance << endl;

    return 0;
}