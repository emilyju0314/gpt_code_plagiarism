#include <iostream>
#include <vector>
using namespace std;

bool isValid(int i, int j, int n) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

int main() {
    int n;
    cin >> n;

    vector<vector<char>> mosaic(n, vector<char>(n));
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mosaic[i][j];
        }
    }

    bool multiple = false;
    bool unique = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mosaic[i][j] == '.') {
                unique = true;
                for (auto dir : directions) {
                    int newRow = i + dir.first;
                    int newCol = j + dir.second;

                    if (isValid(newRow, newCol, n) && mosaic[newRow][newCol] == '.') {
                        unique = false;
                        for (auto dir2 : directions) {
                            int adjRow = newRow + dir2.first;
                            int adjCol = newCol + dir2.second;
                            if (isValid(adjRow, adjCol, n) && mosaic[adjRow][adjCol] == mosaic[i][j]) {
                                unique = true;
                            }
                        }
                        if (!unique) {
                            multiple = true;
                            break;
                        }
                    }
                }
                if (multiple)
                    break;
            }
        }
        if (multiple)
            break;
    }

    if (multiple) {
        cout << "MULTIPLE" << endl;
    } else if (!unique) {
        cout << "NONE" << endl;
    } else {
        cout << "UNIQUE" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mosaic[i][j] == '.') {
                    cout << "S";
                } else {
                    cout << mosaic[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}