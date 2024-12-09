#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<char>> cake(r, vector<char>(c));
    vector<bool> rowContainsEvilStrawberry(r, false);
    vector<bool> colContainsEvilStrawberry(c, false);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> cake[i][j];
            if (cake[i][j] == 'S') {
                rowContainsEvilStrawberry[i] = true;
                colContainsEvilStrawberry[j] = true;
            }
        }
    }

    int totalCells = r * c;
    int maxCells = 0;

    for (int i = 0; i < r; i++) {
        if (!rowContainsEvilStrawberry[i]) {
            maxCells += c;
            rowContainsEvilStrawberry[i] = true;
        }
    }

    for (int j = 0; j < c; j++) {
        if (!colContainsEvilStrawberry[j]) {
            for (int i = 0; i < r; i++) {
                if (cake[i][j] == '.') {
                    maxCells++;
                }
            }
        }
    }

    cout << maxCells << endl;

    return 0;
}