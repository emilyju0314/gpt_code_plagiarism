#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q, p;
    cin >> n >> m >> q >> p;

    vector<vector<char>> capital(n, vector<char>(m));
    vector<vector<int>> noiseLevel(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> capital[i][j];
        }
    }

    // Loop to calculate the noise level for each quarter
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (capital[i][j] >= 'A' && capital[i][j] <= 'Z') {
                int sourceNoise = (capital[i][j] - 'A' + 1) * q;
                // Control the noise spreading from the source
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < m; l++) {
                        // Calculate the distance between the source and the quarter
                        int distance = abs(k - i) + abs(l - j);
                        // Calculate the noise level reaching the quarter
                        noiseLevel[k][l] += sourceNoise / (1 << distance);
                    }
                }
            }
        }
    }

    // Count the number of quarters whose noise level exceeds the allowed level
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (noiseLevel[i][j] > p) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}