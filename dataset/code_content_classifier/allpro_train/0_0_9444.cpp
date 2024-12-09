#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    unordered_map<string, int> word_freq;

    for (int i = 0; i < n; i++) {
        cin >> words[i];
        word_freq[words[i]]++;
    }

    int total_length = n - 1; // Total length of original text
    for (auto it = word_freq.begin(); it != word_freq.end(); it++) {
        total_length += (it->first.length() + 1) * it->second; // Add length of words and spaces
    }

    int min_length = total_length;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            unordered_map<string, int> freq1, freq2;

            for (int k = 0; k < i; k++) {
                freq1[words[k]]++;
            }
            for (int k = i; k < j; k++) {
                freq2[words[k]]++;
            }
            for (int k = j; k < n; k++) {
                freq1[words[k]]++;
            }

            int abbreviation_length = i + (j - i) + (n - j);

            for (auto it1 = freq1.begin(); it1 != freq1.end(); it1++) {
                if (it1->second >= 2) {
                    abbreviation_length += it1->first.length() - 1;
                }
            }
            for (auto it2 = freq2.begin(); it2 != freq2.end(); it2++) {
                if (it2->second >= 2) {
                    abbreviation_length += it2->first.length()- 1;
                }
            }

            min_length = min(min_length, abbreviation_length);
        }
    }

    cout << min_length << endl;

    return 0;
}