#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> cells(M);
    for (int i = 0; i < M; i++) {
        cin >> cells[i].first >> cells[i].second;
    }

    unordered_set<int> black_cells;
    for (auto cell : cells) {
        black_cells.insert(cell.first * N + cell.second);
    }

    int result = M;
    for (auto cell : cells) {
        if (black_cells.count((cell.second-1) * N + cell.first)) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}