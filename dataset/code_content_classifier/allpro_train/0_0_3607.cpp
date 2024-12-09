#include <iostream>
#include <vector>

using namespace std;

// Function to check if a sequence has a period of 2k - 1
bool isLongSequence(vector<int>& sequence, int k) {
    for (int i = 0; i < k; i++) {
        if (sequence[i] != sequence[i + k]) {
            return false;
        }
    }
    return true;
}

int main() {
    int k;
    cin >> k;

    // Try all possible combinations of coefficients
    for (int i = 0; i < (1 << k); i++) {
        vector<int> coefficients;
        for (int j = 0; j < k; j++) {
            coefficients.push_back((i >> j) & 1);
        }

        vector<int> sequence(k, 0);
        for (int j = k; j < 2 * k - 1; j++) {
            int nextTerm = 0;
            for (int l = 0; l < k; l++) {
                nextTerm += coefficients[l] * sequence[j - k + 1 + l];
            }
            sequence.push_back(nextTerm % 2);
        }

        if (isLongSequence(sequence, k)) {
            // Output coefficients
            for (int j = 0; j < k; j++) {
                cout << coefficients[j] << " ";
            }
            cout << endl;

            // Output first k elements of the sequence
            for (int j = 0; j < k; j++) {
                cout << sequence[j] << " ";
            }
            cout << endl;

            return 0;
        }
    }

    // If no long sequence found
    cout << "-1" << endl;

    return 0;
}