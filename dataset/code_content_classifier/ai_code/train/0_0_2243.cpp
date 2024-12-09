#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, h;

    while (true) {
        cin >> n >> h;

        if (n == 0 && h == 0) {
            break;
        }

        vector<vector<vector<int>> no_holes(n, vector<vector<int>>(n, vector<int>(n, 1)));

        while (h--) {
            string ci;
            int ai, bi;
            cin >> ci >> ai >> bi;

            if (ci == "xy") {
                for (int i = 0; i < n; i++) {
                    no_holes[ai-1][bi-1][i] = 0;
                }
            } else if (ci == "xz") {
                for (int i = 0; i < n; i++) {
                    no_holes[ai-1][i][bi-1] = 0;
                }
            } else if (ci == "yz") {
                for (int i = 0; i < n; i++) {
                    no_holes[i][ai-1][bi-1] = 0;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    count += no_holes[i][j][k];
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}