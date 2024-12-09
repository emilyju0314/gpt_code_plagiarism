#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<vector<int>> > cube(n, vector<vector<int>>(n, vector<int>(n)));

    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cube[i][j][k] = num;
                num++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if ((i + j) % 2 == 0) {
                    cout << cube[i][j][k] << " ";
                } else {
                    cout << cube[i][n-1-j][k] << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}