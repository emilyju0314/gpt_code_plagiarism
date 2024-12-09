#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N;
    while (cin >> N && N) {
        vector<int> I(N);
        for (int i = 0; i < N; i++) {
            cin >> I[i];
        }

        double min_entropy = 256; // Set initial min_entropy to maximum value
        int best_S, best_A, best_C;

        for (int S = 0; S <= 15; S++) {
            for (int A = 0; A <= 15; A++) {
                for (int C = 0; C <= 15; C++) {
                    vector<int> R(N);
                    R[0] = S;
                    for (int i = 1; i < N; i++) {
                        R[i] = (A * R[i - 1] + C) % 256;
                    }

                    vector<int> O(N);
                    for (int i = 0; i < N; i++) {
                        O[i] = R[i] ^ I[i]; // Calculating O(⋅) based on R(⋅) and I(⋅)
                    }

                    double entropy = 0.0;
                    for (int x = 0; x < 256; x++) {
                        int count = 0;
                        for (int i = 0; i < N; i++) {
                            if (O[i] == x) {
                                count++;
                            }
                        }
                        double px = (double)count / N;
                        if (count > 0) {
                            entropy -= px * log2(px);
                        }
                    }

                    if (entropy < min_entropy) {
                        min_entropy = entropy;
                        best_S = S;
                        best_A = A;
                        best_C = C;
                    }
                }
            }
        }

        cout << best_S << " " << best_A << " " << best_C << endl;
    }

    return 0;
}