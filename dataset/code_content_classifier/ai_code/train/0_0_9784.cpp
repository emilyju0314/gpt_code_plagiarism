#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k;
    while (cin >> k) {
        if (k == 0) break;

        string initial_sequence, unlocking_sequence;
        cin >> initial_sequence >> unlocking_sequence;

        int rotations = 0;
        for (int i = 0; i < k; ++i) {
            int initial_num = initial_sequence[i] - '0';
            int unlocking_num = unlocking_sequence[i] - '0';
            rotations += min(abs(unlocking_num - initial_num), 10 - abs(unlocking_num - initial_num));
        }

        cout << rotations << endl;
    }

    return 0;
}