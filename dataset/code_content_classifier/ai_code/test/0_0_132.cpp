#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<int> b(7);

        for (int i = 0; i < 7; i++) {
            cin >> b[i];
        }

        // We know the sum of all elements, a1 + a2 + a3 = b[6]
        // We know the sum of all possible pairs, a1 + a2, a1 + a3, a2 + a3 = b[5], b[4], b[3]
        // From these equations, we can determine the values of a1, a2, and a3

        int a3 = (b[3] - b[5] + b[6]) / 2;
        int a2 = (b[4] - b[6] + b[4]) / 2;
        int a1 = b[6] - a2 - a3;

        cout << a1 << " " << a2 << " " << a3 << endl;
    }

    return 0;
}