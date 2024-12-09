#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<int> b(7);
        for (int i = 0; i < 7; i++) {
            cin >> b[i];
        }

        int a3 = b[6]; // largest element is the sum of all elements
        int a1 = b[3] - a3; // smallest element is sum of first 6 elements subtracted from largest element
        int a2 = b[1] - a1; // third element is sum of first 3 elements subtracted from first element

        cout << a1 << " " << a2 << " " << a3 << endl;
    }

    return 0;
}