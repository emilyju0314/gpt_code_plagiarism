#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    int queries = 0;

    for (int i = 1; i <= sqrt(n) && i <= n; i++) {
        if (n % i != 0) continue;

        for (int j = 1; j <= sqrt(m) && j <= m; j++) {
            if (m % j != 0) continue;

            queries++;
            cout << "? " << i << " " << j << " 1 1 " << i << " " << j << endl;
            cout.flush();

            int t;
            cin >> t;

            bool valid = true;
            for (int x = 1; x <= n/i; x++) {
                for (int y = 1; y <= m/j; y++) {
                    queries++;
                    cout << "? " << i << " " << j << " " << (x-1)*i + 1 << " " << (y-1)*j + 1 << " " << x*i << " " << y*j << endl;
                    cout.flush();

                    int t2;
                    cin >> t2;

                    if (t2 != t) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) break;
            }

            if (valid) {
                // Increment the answer if the subrectangles are valid
                matrix[i-1][j-1]++;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            answer += matrix[i][j];
        }
    }

    cout << "! " << answer << endl;

    return 0;
}