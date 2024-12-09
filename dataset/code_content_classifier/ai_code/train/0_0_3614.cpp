#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int A[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    int N;
    cin >> N;
    
    unordered_set<int> bingo;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        bingo.insert(num);
    }

    bool result = false;
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (bingo.count(A[i][0]) && bingo.count(A[i][1]) && bingo.count(A[i][2])) {
            result = true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (bingo.count(A[0][j]) && bingo.count(A[1][j]) && bingo.count(A[2][j])) {
            result = true;
        }
    }

    // Check diagonals
    if (bingo.count(A[0][0]) && bingo.count(A[1][1]) && bingo.count(A[2][2])) {
        result = true;
    }
    if (bingo.count(A[0][2]) && bingo.count(A[1][1]) && bingo.count(A[2][0])) {
        result = true;
    }

    if (result) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}