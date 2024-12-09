#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        bool perfect = false;
        string colors = "";
        int cut = 0;

        for (int i = 0; i < n; i++) {
            if (perfect) break;

            if (i % 2 == 0) {
                colors += "R";
            } else {
                colors += "B";
            }

            for (int j = 1; j < m; j++) {
                if ((matrix[i][j] > matrix[i][j-1] && colors[i] == 'R') ||
                    (matrix[i][j] < matrix[i][j-1] && colors[i] == 'B')) {
                    cut = j;
                    perfect = true;
                    break;
                }
            }
        }

        if (perfect) {
            cout << "YES" << endl;
            cout << colors << " " << cut << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}