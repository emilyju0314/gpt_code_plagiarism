#include <iostream>
#include <vector>

using namespace std;

bool canEraseSequence(vector<int>& sequence) {
    int n = sequence.size();
    for (int i = 0; i < n; i++) {
        if (sequence[i] % (i + 1) != 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> sequence(n);
        for (int i = 0; i < n; i++) {
            cin >> sequence[i];
        }

        if (canEraseSequence(sequence)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}