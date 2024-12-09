#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        // Finding the length of the fourth side of the quadrilateral
        cout << max(max(a, b), c) + 1 << endl;
    }

    return 0;
}