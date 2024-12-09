#include <iostream>
#include <vector>

using namespace std;

bool isGeometricProgression(vector<int> sequence) {
   if (sequence.size() <= 2) {
        return true;
    }
    int ratio = sequence[1] / sequence[0];
    for (int i = 1; i < sequence.size(); i++) {
        if (sequence[i] != sequence[i - 1] * ratio) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    if (isGeometricProgression(sequence)) {
        cout << 0 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            vector<int> modifiedSequence(sequence.begin(), sequence.end());
            modifiedSequence.erase(modifiedSequence.begin() + i);
            if (isGeometricProgression(modifiedSequence)) {
                cout << 1 << endl;
                return 0;
            }
        }
        cout << 2 << endl;
    }

    return 0;
}