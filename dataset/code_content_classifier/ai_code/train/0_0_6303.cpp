#include <iostream>
#include <string>

using namespace std;

int main() {
    string S_A, S_B, S_C;
    cin >> S_A >> S_B >> S_C;

    int idx_A = 0, idx_B = 0, idx_C = 0;
    char currentPlayer = 'A';

    while (true) {
        if (currentPlayer == 'A') {
            if (idx_A >= S_A.length() || S_A[idx_A] == '\0') {
                cout << "A" << endl;
                break;
            }
            currentPlayer = S_A[idx_A];
            idx_A++;
        } else if (currentPlayer == 'B') {
            if (idx_B >= S_B.length() || S_B[idx_B] == '\0') {
                cout << "B" << endl;
                break;
            }
            currentPlayer = S_B[idx_B];
            idx_B++;
        } else if (currentPlayer == 'C') {
            if (idx_C >= S_C.length() || S_C[idx_C] == '\0') {
                cout << "C" << endl;
                break;
            }
            currentPlayer = S_C[idx_C];
            idx_C++;
        }
    }

    return 0;
}