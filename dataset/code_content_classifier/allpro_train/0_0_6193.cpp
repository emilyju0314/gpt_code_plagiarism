#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countDeputies(int n, int m, char presidentColor, vector<vector<char>>& officeRoom) {
    int deputies = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (officeRoom[i][j] == presidentColor) {
                if (i > 0 && officeRoom[i-1][j] != '.') deputies++;
                if (i < n-1 && officeRoom[i+1][j] != '.') deputies++;
                if (j > 0 && officeRoom[i][j-1] != '.') deputies++;
                if (j < m-1 && officeRoom[i][j+1] != '.') deputies++;
            }
        }
    }
    return deputies;
}

int main() {
    int n, m;
    char presidentColor;
    cin >> n >> m >> presidentColor;

    vector<vector<char>> officeRoom(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> officeRoom[i][j];
        }
    }

    int deputies = countDeputies(n, m, presidentColor, officeRoom);
    cout << deputies << endl;

    return 0;
}