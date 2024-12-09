#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSymmetrical(vector<string>& coaster) {
    int n = coaster.size();
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            if (coaster[i][j] != coaster[n - i - 1][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int C, N;
    cin >> C >> N;

    vector<string> first_coaster(N);
    for (int i = 0; i < N; i++) {
        cin >> first_coaster[i];
    }

    int symmetrical_count = 0;

    for (int i = 0; i < C - 1; i++) {
        int D;
        cin >> D;

        vector<string> current_coaster = first_coaster;
        for (int j = 0; j < D; j++) {
            int r, c;
            cin >> r >> c;
            if (current_coaster[r - 1][c - 1] == '0') {
                current_coaster[r - 1][c - 1] = '1';
            } else {
                current_coaster[r - 1][c - 1] = '0';
            }
        }

        first_coaster = current_coaster;

        if (isSymmetrical(first_coaster) && isSymmetrical(current_coaster)) {
            symmetrical_count++;
        }
    }

    cout << symmetrical_count << endl;

    return 0;
}