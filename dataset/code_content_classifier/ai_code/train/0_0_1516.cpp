#include <iostream>
#include <vector>

using namespace std;

bool isIncreasingSequence(vector<string> sequence) {
    for (int i = 1; i < sequence.size(); i++) {
        if (sequence[i] <= sequence[i-1]) {
            return false;
        }
    }
    return true;
}

bool fillMissingDigits(vector<string>& sequence) {
    for (int i = 0; i < sequence.size(); i++) {
        if (sequence[i][0] == '0') {
            return false;
        }
        bool hasQuestionMark = false;
        for (char c : sequence[i]) {
            if (c == '?') {
                hasQuestionMark = true;
            }
        }
        if (hasQuestionMark) {
            if (i == 0 || sequence[i-1].size() == sequence[i].size()) {
                sequence[i] = sequence[i-1];
            } else {
                sequence[i] = sequence[i-1].substr(0, sequence[i-1].size() - sequence[i].size()) + sequence[i];
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<string> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    if (!fillMissingDigits(sequence)) {
        cout << "NO" << endl;
    } else {
        if (isIncreasingSequence(sequence)) {
            cout << "YES" << endl;
            for (string num : sequence) {
                cout << num << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}