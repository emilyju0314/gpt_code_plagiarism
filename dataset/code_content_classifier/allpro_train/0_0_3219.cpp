#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k;
    cin >> k;

    vector<pair<string, int>> strings_cost;
    for (int i = 0; i < k; i++) {
        string t;
        int c;
        cin >> t >> c;
        strings_cost.push_back({t, c});
    }

    string S;
    cin >> S;

    // Find the maximum value of S after replacing all question marks with pairwise distinct lowercase Latin letters
    int max_value = 0;
    for (char a = 'a'; a <= 'n'; a++) {
        for (char b = 'a'; b <= 'n'; b++) {
            if (a != b) {
                int value = 0;
                for (auto [t, c] : strings_cost) {
                    int count = 0;
                    for (size_t i = 0; i <= S.size() - t.size(); i++) {
                        bool match = true;
                        for (size_t j = 0; j < t.size(); j++) {
                            if (S[i + j] != '?' && S[i + j] != t[j]) {
                                match = false;
                                break;
                            }
                        }
                        if (match) {
                            count++;
                        }
                    }
                    value += count * c;
                }
                max_value = max(max_value, value);
            }
        }
    }

    cout << max_value << endl;

    return 0;
}