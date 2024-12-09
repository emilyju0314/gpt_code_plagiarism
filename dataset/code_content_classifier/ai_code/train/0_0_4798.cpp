#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> employees(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> employees[i][j];
        }
    }

    vector<int> notifications(n, 0);
    for (int i = 0; i < k; i++) {
        int xi, yi;
        cin >> xi >> yi;
        xi--; yi--; // adjust to 0-based indexing

        for (int j = 0; j < n; j++) {
            if (employees[j][yi] == 1 && j != xi) {
                notifications[j]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << notifications[i] << " ";
    }

    return 0;
}