#include <iostream>
#include <vector>

using namespace std;

int countSpruces(vector<string>& matrix, int n, int m) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '*') {
                int k = 1;
                while (i + k < n && j - k + 1 >= 0 && j + k - 1 < m) {
                    bool validSpruce = true;
                    for (int l = j - k + 1; l <= j + k - 1; l++) {
                        if (matrix[i + k][l] != '*') {
                            validSpruce = false;
                            break;
                        }
                    }
                    if (validSpruce) {
                        count++;
                        k++;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> matrix(n);
        for (int i = 0; i < n; i++) {
            cin >> matrix[i];
        }

        int result = countSpruces(matrix, n, m);
        cout << result << endl;
    }

    return 0;
}