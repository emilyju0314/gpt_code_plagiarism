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

        int a1 = b[0];
        int a3 = b[6];
        int a2 = -1;

        vector<int> possible_a2;
        for (int i = 1; i < 6; i++) {
            if (b[0] + b[6] - b[i] == b[i]) {
                possible_a2.push_back(b[i]);
            }
        }

        sort(possible_a2.begin(), possible_a2.end());

        a2 = possible_a2[0];

        cout << a1 << " " << a2 << " " << a3 << endl;
    }

    return 0;
}