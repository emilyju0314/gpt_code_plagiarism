#include <iostream>
#include <vector>

using namespace std;

bool isAliceWinner(vector<int>& A) {
    int left = 0, right = A.size() - 1;
    int prev = 0;
    bool aliceTurn = true;

    while (left <= right) {
        if (A[left] > prev && A[right] > prev) {
            if (A[left] > A[right]) {
                prev = A[right];
                right--;
            } else {
                prev = A[left];
                left++;
            }
        } else if (A[left] > prev) {
            prev = A[left];
            left++;
        } else if (A[right] > prev) {
            prev = A[right];
            right--;
        } else {
            break;
        }

        aliceTurn = !aliceTurn;
    }

    return !aliceTurn;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    if (isAliceWinner(A)) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }

    return 0;
}