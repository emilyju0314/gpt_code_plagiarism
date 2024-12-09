#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> tricks(n, vector<int>(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> tricks[i][j];
        }
    }

    long long result = 0;
    for (int l = 0; l < n; l++) {
        unordered_set<int> variations;
        vector<int> deck(k);
        for (int i = 0; i < k; i++) deck[i] = i + 1;

        for (int r = l; r < n; r++) {
            unordered_set<int> seen;
            long long current_variations = 1;
            for (int i = l; i <= r; i++) {
                if (seen.count(i)) continue;

                vector<int> new_deck(k);
                for (int j = 0; j < k; j++) {
                    new_deck[j] = deck[tricks[i][j] - 1];
                }

                if (variations.count(0) == 0) {
                    variations.insert(0);
                } else {
                    variations.erase(0);
                    for (int j = 0; j < current_variations; j++) {
                        for (int p = 0; p < k; p++) {
                            int val = p * current_variations + j;
                            variations.insert(val);
                            for (int q = 1; q < k; q++) {
                                variations.insert(val ^ (1 << q));
                            }
                        }
                    }
                }
                seen.insert(i);

                int new_variations = 0;
                for (int var : variations) {
                    int new_var = 0;
                    for (int j = 0; j < k; j++) {
                        new_var ^= 1 << new_deck[j] - 1;
                    }
                    new_variations |= new_var;
                }

                variations.clear();
                variations.insert(new_variations);

                deck = new_deck;
                current_variations = variations.size();
            }

            result += variations.size();
        }
    }

    cout << result << endl;

    return 0;
}