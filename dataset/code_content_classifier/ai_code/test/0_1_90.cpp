#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;

        if (x > y) {
            cout << x << endl; // If x is greater than y, n can be equal to x
        } else {
            cout << y << endl; // If x is less than y, n can be equal to y
        }
    }

    return 0;
}