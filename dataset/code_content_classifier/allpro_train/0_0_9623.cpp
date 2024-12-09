#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;

        // Calculate the number of rolls needed to get exactly x points
        int rolls = (x + 6 - 1) / 6;

        cout << rolls << endl;
    }

    return 0;
}