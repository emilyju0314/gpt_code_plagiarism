#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m, dx, dy;
    cin >> n >> m >> dx >> dy;

    vector<pair<int, int>> apples;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        apples.push_back({x, y});
    }

    int max_count = 0;
    pair<int, int> start_cell = {0, 0};

    for (int i = 0; i < min(n, m); i++) {
        unordered_set<int> visited;
        int count = 0;
        pair<int, int> curr_cell = {i * dx % n, i * dy % n};

        while (visited.find(curr_cell.first * n + curr_cell.second) == visited.end()) {
            visited.insert(curr_cell.first * n + curr_cell.second);
            for (const auto& apple : apples) {
                if (curr_cell.first == apple.first && curr_cell.second == apple.second) {
                    count++;
                }
            }
            curr_cell = {(curr_cell.first + dx) % n, (curr_cell.second + dy) % n};
        }

        if (count > max_count) {
            max_count = count;
            start_cell = {i * dx % n, i * dy % n};
        }
    }

    cout << start_cell.first << " " << start_cell.second << endl;

    return 0;
}