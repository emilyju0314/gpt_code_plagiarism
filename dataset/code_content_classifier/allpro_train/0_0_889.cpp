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
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
                totalSum += matrix[i][j];
            }
        }

        if (totalSum == 0) {
            cout << "Jeel" << endl;
        } else {
            cout << ((n + m) % 2 == 0 ? "Jeel" : "Ashish") << endl;
        }
    }

    return 0;
}