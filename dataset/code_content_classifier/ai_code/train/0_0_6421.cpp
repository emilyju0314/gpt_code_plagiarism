#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

bool has_ascent(const vector<int>& sequence) {
    for (int i = 0; i < sequence.size() - 1; i++) {
        if (sequence[i] < sequence[i+1]) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    unordered_map<int, vector<int>> sequences;
    int total_count = 0;

    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        
        vector<int> sequence(l);
        for (int j = 0; j < l; j++) {
            cin >> sequence[j];
        }

        sequences[i] = sequence;

        if (has_ascent(sequence)) {
            total_count += pow(n, 2);
        }
    }

    for (auto it1 = sequences.begin(); it1 != sequences.end(); it1++) {
        for (auto it2 = sequences.begin(); it2 != sequences.end(); it2++) {
            vector<int> concatenated = it1->second;
            concatenated.insert(concatenated.end(), it2->second.begin(), it2->second.end());

            if (has_ascent(concatenated)) {
                total_count++;
            }
        }
    }

    cout << total_count << endl;

    return 0;
}