#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int r, n;
    cin >> r >> n;

    vector<pair<int, int>> cells;
    for (int i = 0; i < n; i++) {
        int ri, ci;
        cin >> ri >> ci;
        cells.push_back({ri, ci});
    }

    sort(cells.begin(), cells.end());

    int remaining_cells = 2 * r - n;
    int last_reclaimed_row = 0;
    string winner = "WIN";

    for (int i = 0; i < n; i++) {
        if (cells[i].first - last_reclaimed_row <= 1) {
            winner = "LOSE";
            break;
        }
        last_reclaimed_row = cells[i].first;
        remaining_cells--;
    }

    if (remaining_cells % 2 == 1) {
        winner = (winner == "WIN") ? "LOSE" : "WIN";
    }

    cout << winner << endl;

    return 0;
}