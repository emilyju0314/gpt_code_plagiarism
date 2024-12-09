#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> cake(n);
    for (int i = 0; i < n; i++) {
        cin >> cake[i];
    }

    int happiness = 0;
    for (int i = 0; i < n; i++) {
        int chocolatesInRow = 0;
        int chocolatesInColumn = 0;
        for (int j = 0; j < n; j++) {
            if (cake[i][j] == 'C') {
                chocolatesInRow++;
            }
            if (cake[j][i] == 'C') {
                chocolatesInColumn++;
            }
        }
        happiness += chocolatesInRow * (chocolatesInRow - 1) / 2;
        happiness += chocolatesInColumn * (chocolatesInColumn - 1) / 2;
    }

    cout << happiness << endl;

    return 0;
}