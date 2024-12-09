#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string S, T;
    int q;
    cin >> S >> T >> q;

    int n = S.length();
    int m = T.length();

    // Precompute prefix sum of occurrences of each character in T
    vector<vector<int>> prefix_sum(26, vector<int>(m+1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 26; j++) {
            prefix_sum[j][i+1] = prefix_sum[j][i] + (T[i] == 'a' + j);
        }
    }

    for (int i = 0; i < q; i++) {
        int l, r, k, x, y;
        cin >> l >> r >> k >> x >> y;

        // Initialize variables for the most interesting option
        int best_option = -1;
        int best_score = INT_MAX;

        // Check each possible position to insert T into S
        for (int j = l; j <= r; j++) {
            int score = 0;

            // Count the occurrences of each character in the resulting string
            vector<int> freq(26, 0);
            for (int p = 0; p < n + m; p++) {
                if (p < j) {
                    if (p < n) {
                        freq[S[p] - 'a']++;
                    }
                } else if (p < j + m) {
                    freq[T[p - j] - 'a']++;
                    if (p - j >= x && p - j <= y) {
                        score += prefix_sum[T[p - j] - 'a'][p - j - x + 1] - prefix_sum[T[p - j] - 'a'][p - j - y];
                    }
                } else {
                    if (p - m < n) {
                        freq[S[p - m] - 'a']++;
                    }
                }
            }

            // Calculate the lexicographically smallest string
            string result;
            for (int p = 0; p < 26; p++) {
                result += string(freq[p], 'a' + p);
            }

            // Update the best option if the current one is more interesting
            if (score < best_score) {
                best_option = j;
                best_score = score;
            }
        }

        // Output the best option for the current question
        cout << best_option << " ";
    }

    cout << endl;

    return 0;
}