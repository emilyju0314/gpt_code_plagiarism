#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int left = 0, right = N - 1;
    int last = 0;
    bool aliceTurn = true;

    while (left <= right) {
        if (A[left] > last && A[right] > last) {
            if (A[left] < A[right]) {
                last = A[left];
                left++;
            } else {
                last = A[right];
                right--;
            }
        } else if (A[left] > last) {
            last = A[left];
            left++;
        } else if (A[right] > last) {
            last = A[right];
            right--;
        } else {
            break;
        }

        aliceTurn = !aliceTurn;
    }

    if (aliceTurn) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }

    return 0;
}