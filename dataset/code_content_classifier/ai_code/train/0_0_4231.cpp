#include<iostream>
#include<vector>
using namespace std;

int main() {
    int X, Y, n;
    while (cin >> X >> Y >> n) {
        if (X == 0 && Y == 0 && n == 0) break;

        vector<pair<int, int>> memo(n); // Stores buyer number and number of parcels bought
        vector<vector<int>> partition(Y, vector<int>(X)); // Stores sign information

        // Input memo information
        for (int i = 0; i < n; i++) {
            int b, k;
            cin >> b >> k;
            memo[i] = make_pair(b, k);
        }

        // Input sign information
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                cin >> partition[i][j];
            }
        }

        bool no_solution = false;
        vector<vector<int>> result(Y, vector<int>(X, -1)); // Stores buyer information

        // Check each partition to assign buyers
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                int buyer = partition[i][j];
                if (buyer == 0) {
                    result[i][j] = 0; // Mark as not assigned
                } else {
                    for (int k = 0; k < n; k++) {
                        if (memo[k].first == buyer) {
                            if (memo[k].second > 0) {
                                result[i][j] = buyer;
                                memo[k].second--;
                                break;
                            } else {
                                no_solution = true;
                                break;
                            }
                        }
                    }
                    if (result[i][j] == -1) {
                        no_solution = true;
                        break;
                    }
                }
            }
            if (no_solution) break;
        }

        // Output result
        if (no_solution) {
            cout << "NA" << endl;
        } else {
            for (int i = 0; i < Y; i++) {
                for (int j = 0; j < X; j++) {
                    cout << result[i][j];
                    if (j < X - 1) cout << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}