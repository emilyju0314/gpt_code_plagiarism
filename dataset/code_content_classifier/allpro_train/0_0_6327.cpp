#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, h;
    cin >> n >> m >> h;

    vector<int> front_view(m);
    for (int i = 0; i < m; i++) {
        cin >> front_view[i];
    }

    vector<int> left_view(n);
    for (int i = 0; i < n; i++) {
        cin >> left_view[i];
    }

    vector<vector<int>> top_view(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> top_view[i][j];
        }
    }

    vector<vector<int>> result(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = min(front_view[j], left_view[i]);
            if (top_view[i][j] == 0) {
                result[i][j] = 0;
            }
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}