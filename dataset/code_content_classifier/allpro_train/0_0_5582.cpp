#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string cellState;
    int changedBits = 0;

    cin >> n >> cellState;

    for (int i = n-1; i >= 0; i--) {
        if (cellState[i] == '0') {
            cellState[i] = '1';
            changedBits = n - i;
            break;
        } else {
            cellState[i] = '0';
        }
    }

    cout << changedBits << endl;

    return 0;
}