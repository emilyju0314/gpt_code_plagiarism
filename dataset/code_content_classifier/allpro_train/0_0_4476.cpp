#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string n;
    cin >> n;

    int moves = -1;

    // Check if the number is already divisible by 25
    if (stoi(n) % 25 == 0) {
        cout << 0 << endl;
        return 0;
    }

    // Try all possible swaps of adjacent digits to find the minimum number of moves
    for (int i = 0; i < n.size() - 1; i++) {
        if ((n[i] == '2' && n[i+1] == '5') || (n[i] == '5' && n[i+1] == '0')) {
            moves = 0;
            break;
        }
        if ((n[i] == '5' && n[i+1] == '2') || (n[i] == '0' && n[i+1] == '5')) {
            moves = 1;
            break;
        }
        if ((n[i] == '2' && n[i+1] == '0') || (n[i] == '5' && n[i+1] == '5')) {
            moves = 2;
            break;
        }
        if ((n[i] == '5' && n[i+1] == '0') || (n[i] == '0' && n[i+1] == '2')) {
            moves = 2;
        }
    }

    cout << moves << endl;

    return 0;
}