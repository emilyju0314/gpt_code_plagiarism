#include <iostream>
#include <vector>

using namespace std;

char getChar(int i, int j) {
    if ((i+j) % 2 == 0) {
        if (i % 2 == 0) {
            if (j % 2 == 0) {
                return 'A';
            } else {
                return 'G';
            }
        } else {
            if (j % 2 == 0) {
                return 'C';
            } else {
                return 'T';
            }
        }
    } else {
        if (i % 2 == 0) {
            if (j % 2 == 0) {
                return 'T';
            } else {
                return 'C';
            }
        } else {
            if (j % 2 == 0) {
                return 'G';
            } else {
                return 'A';
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> table(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }

    vector<vector<char>> niceTable(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            niceTable[i][j] = getChar(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (table[i][j] == niceTable[i][j]) {
                cout << getChar(i, j);
            } else {
                cout << table[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}