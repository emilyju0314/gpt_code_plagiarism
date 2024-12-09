#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPossible(int N, string A) {
    vector<int> ones;
    for (int i = 0; i < (1 << N); i++) {
        if (A[i] == '1') {
            ones.push_back(i);
        }
    }

    for (int mask = 0; mask < (1 << N); mask++) {
        bool valid = true;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                int x = (mask ^ (1 << i));
                bool found = false;
                for (int j = 0; j < ones.size(); j++) {
                    if (ones[j] == x) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            return true;
        }
    }
    return false;
}

void constructCurve(int N, string A) {
    if (!isPossible(N, A)) {
        cout << "Impossible" << endl;
        return;
    }

    cout << "Possible" << endl;
    cout << 4 << endl;
    cout << "0 0" << endl;
    cout << "0 1" << endl;
    cout << "1 1" << endl;
    cout << "1 0" << endl;
    cout << "0 0" << endl;
}

int main() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    constructCurve(N, A);

    return 0;
}