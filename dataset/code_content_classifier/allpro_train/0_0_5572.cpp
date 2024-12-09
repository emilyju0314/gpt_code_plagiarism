#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> table(n);
    for (int i = 0; i < n; i++) {
        cin >> table[i];
    }

    int min_moves = m;
    bool found_solution = false;
    for (int col = 0; col < m; col++) {
        int moves = 0;
        for (int row = 0; row < n; row++) {
            int right_shifts = 0;
            int left_shifts = 0;
            while (table[row][(col + right_shifts) % m] == '0' && right_shifts < m) {
                right_shifts++;
            }
            while (table[row][(col - left_shifts + m) % m] == '0' && left_shifts < m) {
                left_shifts++;
            }

            if (right_shifts == m || left_shifts == m) {
                moves = m;
                break;
            } else {
                moves += min(right_shifts, left_shifts);
            }
        }

        if (moves < min_moves) {
            min_moves = moves;
            found_solution = true;
        }
    }

    if (found_solution) {
        cout << min_moves << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}