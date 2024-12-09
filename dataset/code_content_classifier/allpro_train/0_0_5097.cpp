#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void neighborJoining(vector<vector<int>>& D) {
    int N = D.size();

    if (N == 2) {
        cout << "2" << endl;
        cout << "2" << endl;
        return;
    }

    // Initialize degrees of internal nodes
    vector<int> degrees(N, 2);

    while (N > 2) {
        // Compute the Q-matrix
        vector<vector<int>> Q(N, vector<int>(N, 0));
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                int sum_dist = 0;
                for (int k = 0; k < N; ++k) {
                    sum_dist += D[i][k];
                    sum_dist += D[j][k];
                }
                Q[i][j] = (N - 2) * D[i][j] - sum_dist;
            }
        }

        // Find the minimum element in the Q-matrix
        int minQ = INF, min_i, min_j;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (Q[i][j] < minQ) {
                    minQ = Q[i][j];
                    min_i = i;
                    min_j = j;
                }
            }
        }

        // Compute r(i) and r(j)
        int r_i = 0, r_j = 0;
        for (int k = 0; k < N; ++k) {
            r_i += D[min_i][k];
            r_j += D[min_j][k];
        }
        int limb_i = (D[min_i][min_j] + r_i - r_j) / 2;
        int limb_j = D[min_i][min_j] - limb_i;

        // Update distance matrix
        vector<int> new_D(N - 1, 0);
        for (int k = 0; k < N; ++k) {
            if (k != min_i && k != min_j) {
                new_D[k] = (D[min_i][k] + D[min_j][k] - D[min_i][min_j]) / 2;
            }
        }

        // Update internal degrees
        degrees.push_back(degrees[min_i] + degrees[min_j]);
        degrees[min_i] = degrees[min_j] = 0;

        // Remove rows and columns of min_i and min_j
        D.erase(D.begin() + min_j);
        D.erase(D.begin() + min_i);
        for (int k = 0; k < N - 2; ++k) {
            D[k].erase(D[k].begin() + min_j);
            D[k].erase(D[k].begin() + min_i);
        }

        // Add new leaf with distances to other leaves
        D.push_back(new_D);
        new_D.push_back(0);
        N--;

        // Output degrees of internal nodes
        sort(degrees.begin(), degrees.end());
        for (int i = 0; i < degrees.size(); ++i) {
            if (degrees[i] > 0) {
                cout << degrees[i] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int N;
    while (true) {
        cin >> N;
        if (N == 0) break;

        vector<vector<int>> D(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> D[i][j];
            }
        }

        neighborJoining(D);
    }

    return 0;
}