#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> wants(n, vector<int>(3));
    vector<vector<int>> tests(n, vector<int>(3));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> wants[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> tests[i][j];
        }
    }

    vector<int> ct(n); // Configuration of CT
    vector<pair<int, int>> cd; // CD pairs

    ct[0] = 1; // CT is set up on the development server

    for (int i = 0; i < n; i++) {
        if (wants[i][0] && tests[i][0]) {
            cd.push_back({1, i + 1});
        }
    }

    cout << "Possible\n";
    for (int i = 0; i < n; i++) {
        cout << ct[i] << " ";
    }
    cout << "\n";

    cout << cd.size() << "\n";
    for (auto p : cd) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}