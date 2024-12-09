#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    vector<vector<int>> d(A, vector<int>(B));
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            cin >> d[i][j];
        }
    }

    int min_distance = 101;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            bool valid = true;
            for (int x = 0; x < A; x++) {
                for (int y = 0; y < B; y++) {
                    if (d[x][y] != min(d[x][j] + i, d[i][y] + j)) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) {
                    break;
                }
            }
            if (valid) {
                cout << "Possible" << endl;
                cout << A + 1 << " " << A + 2 << endl;
                
                for (int x = 1; x <= A; x++) {
                    cout << x << " " << x + 1 << " X" << endl;
                }
                cout << 1 << " " << A + 2 << " Y" << endl;
                cout << 1 << " " << A + 2 << endl;
                return 0;
            }
        }
    }

    cout << "Impossible" << endl;

    return 0;
}