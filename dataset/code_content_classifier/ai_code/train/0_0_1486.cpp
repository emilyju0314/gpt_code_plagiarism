#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> field(2*n, vector<int>(2*m, 0));

    // Read the initial field
    for(int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for(int j = 0; j < m; j++) {
            field[i][j] = row[j] - '0';
        }
    }

    // Build the infinite field
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            field[i+n][j] = field[i][j] ^ 1; // Inverted field to the right
            field[i][j+m] = field[i][j] ^ 1; // Inverted field to the bottom
            field[i+n][j+m] = field[i][j]; // Current field to the bottom right
        }
    }

    // Calculate prefix sums for rows and columns
    vector<vector<int>> rowPrefixSum(2*n, vector<int>(2*m, 0));
    vector<vector<int>> colPrefixSum(2*n, vector<int>(2*m, 0));

    for(int i = 0; i < 2*n; i++) {
        for(int j = 0; j < 2*m; j++) {
            rowPrefixSum[i][j] = field[i][j];
            if(j > 0) {
                rowPrefixSum[i][j] += rowPrefixSum[i][j-1];
            }
        }
    }

    for(int j = 0; j < 2*m; j++) {
        for(int i = 0; i < 2*n; i++) {
            colPrefixSum[i][j] = field[i][j];
            if(i > 0) {
                colPrefixSum[i][j] += colPrefixSum[i-1][j];
            }
        }
    }

    // Process queries
    for(int query = 0; query < q; query++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int sum = 0;

        // Calculate the sum using prefix sums
        sum += rowPrefixSum[x2-1][y2-1];
        if(y1 > 1) {
            sum -= rowPrefixSum[x2-1][y1-2];
        }
        if(x1 > 1) {
            sum -= colPrefixSum[x1-2][y2-1];
        }
        if(x1 > 1 && y1 > 1) {
            sum += colPrefixSum[x1-2][y1-2];
        }

        cout << sum << endl;
    }

    return 0;
}