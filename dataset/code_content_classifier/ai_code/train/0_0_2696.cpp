#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canWaterFlow(int n, string row1, string row2) {
    // Check if the last pipe in the first row and the first pipe in the second row are straight pipes
    if (row1[n-1] == '1' || row1[n-1] == '2') {
        if (row2[0] == '1' || row2[0] == '2') {
            return true;
        }
    }

    // Check if the last pipe in the first row and the first pipe in the second row are curved pipes in a way that allow water flow
    if ((row1[n-1] == '3' && row2[0] == '4') || (row1[n-1] == '4' && row2[0] == '3')) {
        return true;
    }
    if ((row1[n-1] == '5' && row2[0] == '6') || (row1[n-1] == '6' && row2[0] == '5')) {
        return true;
    }

    return false;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        string row1, row2;
        cin >> row1 >> row2;

        if (canWaterFlow(n, row1, row2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}