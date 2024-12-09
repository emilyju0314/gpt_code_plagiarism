#include <iostream>

using namespace std;

int main() {
    int row, col;
    cin >> row >> col;

    if ((row >= 0 && row <= 7) && (col >= 0 && col <= 7) || 
        (row >= 56 && row <= 63) && (col >= 0 && col <= 7) || 
        (row >= 0 && row <= 7) && (col >= 56 && col <= 63) || 
        (row >= 56 && row <= 63) && (col >= 56 && col <= 63)) {
        cout << "IN" << endl;
    } else {
        cout << "OUT" << endl;
    }

    return 0;
}