#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> parkingLot(4, vector<int>(n));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cin >> parkingLot[i][j];
        }
    }

    vector<pair<int, int>> carPositions(k+1);
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= 2; j++) {
            for (int l = 0; l < n; l++) {
                if (parkingLot[j][l] == i) {
                    carPositions[i] = make_pair(j, l);
                }
            }
        }
    }

    vector<pair<int, int>> parkingSpots(k+1);
    for (int i = 1; i <= k; i++) {
        if (parkingLot[0][i-1] == i) {
            parkingSpots[i] = make_pair(0, i-1);
        } else {
            parkingSpots[i] = make_pair(3, i-1);
        }
    }

    vector<pair<int, pair<int, int>>> moves;
    int moveCount = 0;

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < abs(carPositions[i].first - parkingSpots[i].first); j++) {
            int newRow = (carPositions[i].first < parkingSpots[i].first) ? carPositions[i].first + 1 : carPositions[i].first - 1;
            moves.push_back(make_pair(i, make_pair(newRow, carPositions[i].second + 1)));
            moveCount++;
            carPositions[i].first = newRow;
        }

        for (int j = 0; j < abs(carPositions[i].second - parkingSpots[i].second); j++) {
            int newCol = (carPositions[i].second < parkingSpots[i].second) ? carPositions[i].second + 1 : carPositions[i].second - 1;
            moves.push_back(make_pair(i, make_pair(carPositions[i].first, newCol)));
            moveCount++;
            carPositions[i].second = newCol;
        }

        if (carPositions[i].first != parkingSpots[i].first || carPositions[i].second != parkingSpots[i].second) {
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << moveCount << endl;
    for (auto move : moves) {
        cout << move.first << " " << move.second.first+1 << " " << move.second.second+1 << endl;
    }

    return 0;
}