#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        int n, m;
        stringstream ss(line);
        ss >> n >> m;

        vector<vector<string>> data(n, vector<string>(m));
        map<string, pair<int, int>> check;

        for (int i = 0; i < n; i++) {
            getline(cin, line);
            stringstream ss(line);
            for (int j = 0; j < m; j++) {
                ss >> data[i][j];
            }
        }

        bool found = false;
        int r1, r2, c1, c2;

        for (int i = 0; i < n && !found; i++) {
            for (int j = i + 1; j < n && !found; j++) {
                bool duplicate = false;
                for (int k = 0; k < m && !duplicate; k++) {
                    if (data[i][k] == data[j][k]) {
                        duplicate = true;
                        r1 = i + 1;
                        r2 = j + 1;
                        c1 = k + 1;
                        c2 = k + 1;
                    }
                }
                if (duplicate) {
                    found = true;
                }
            }
        }

        if (found) {
            cout << "YES" << endl;
            cout << r1 << " " << r2 << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}