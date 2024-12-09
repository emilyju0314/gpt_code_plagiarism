#include <iostream>
#include <vector>

using namespace std;

int minimumOperationsToPortal(int n, int m, vector<string>& A) {
    int operations = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 || i == n-1) && (j == 0 || j == m-1)) {
                continue;
            }
            if (A[i][j] == '1') {
                operations++;
            }
        }
    }

    return operations;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        vector<string> A(n);
        for (int j = 0; j < n; j++) {
            cin >> A[j];
        }

        cout << minimumOperationsToPortal(n, m, A) << endl;
    }

    return 0;
}