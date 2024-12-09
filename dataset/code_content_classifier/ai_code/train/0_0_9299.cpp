#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> operations(k, vector<int>(n, 0));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            operations[i][j] = min(j+1, n);
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cout << operations[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}