#include <iostream>
#include <vector>

using namespace std;

int main() {
    int datasets;
    cin >> datasets;

    // Process each dataset
    for(int d = 0; d < datasets; d++) {
        int n, m, k;
        cin >> n >> m >> k;

        // Store the current horizontal lines
        vector<int> horizontalLines(n-1, 0);
        
        // Input the current horizontal lines
        for(int i = 0; i < m; i++) {
            int h, x;
            cin >> h >> x;
            x--; // Adjust index starting from 0
            horizontalLines[x] = h;
        }

        // Calculate the minimum number of horizontal lines needed to hit Actagawa for each vertical line
        vector<int> result(n, 0);
        for(int i = 0; i < n; i++) {
            // Calculate the number of horizontal lines needed for each vertical line
            for(int j = 0; j < i; j++) {
                result[i] += max(0, horizontalLines[j] - result[j]);
            }
        }

        // Output the result for each vertical line
        for(int i = 0; i < n; i++) {
            cout << result[i] << endl;
        }
    }

    return 0;
}