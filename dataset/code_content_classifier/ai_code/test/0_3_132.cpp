#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        vector<int> b(7);
        for(int i = 0; i < 7; i++) {
            cin >> b[i];
        }

        // b_6 = a_1 + a_2
        // b_5 = a_1 + a_3
        // b_4 = a_2 + a_3
        // b_3 = a_1 + a_2 + a_3

        // Solve for a_1, a_2, a_3
        int a1 = b[0];
        int a3 = b[6] - a1;
        int a2 = b[5] - a3;

        cout << a1 << " " << a2 << " " << a3 << endl;
    }

    return 0;
}