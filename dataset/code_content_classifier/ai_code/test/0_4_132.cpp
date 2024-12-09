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

        int a1, a2, a3;

        a3 = b[6]; // last element of original array is the largest sum
        a2 = b[3] - a3; // second largest sum minus last element gives second element of array
        a1 = b[0] - a2; // largest sum minus second element gives first element of array

        cout << a1 << " " << a2 << " " << a3 << endl;
    }

    return 0;
}