#include <iostream>
#include <vector>

using namespace std;

bool canStartRoundDance(vector<int>& indices) {
    int n = indices.size();
    int clockwiseStart = -1;
    int counterclockwiseStart = -1;

    for (int i = 0; i < n; i++) {
        if (indices[i] == 1) {
            clockwiseStart = i;
        }
        if (indices[i] == n) {
            counterclockwiseStart = i;
        }
    }

    if (clockwiseStart == (counterclockwiseStart + 1) % n) {
        return true;
    }

    return false;
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;

        vector<int> indices(n);
        for (int j = 0; j < n; j++) {
            cin >> indices[j];
        }

        if (canStartRoundDance(indices)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}