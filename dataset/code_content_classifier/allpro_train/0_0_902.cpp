#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;

    vector<vector<int>> guitar(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> guitar[i][j];
        }
    }

    vector<int> song(s);
    for (int i = 0; i < s; i++) {
        cin >> song[i];
    }

    int max_complexity = 0;
    for (int i = 0; i < s-1; i++) {
        int note1 = song[i];
        int note2 = song[i+1];

        int string1, string2, fret1, fret2;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (guitar[x][y] == note1) {
                    string1 = x;
                    fret1 = y;
                }
                if (guitar[x][y] == note2) {
                    string2 = x;
                    fret2 = y;
                }
            }
        }

        int complexity = abs(string1 - string2) + abs(fret1 - fret2);
        max_complexity = max(max_complexity, complexity);
    }

    cout << max_complexity << endl;

    return 0;
}