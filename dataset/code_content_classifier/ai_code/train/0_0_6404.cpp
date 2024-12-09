#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int operations = 0;
    for (int i = 1; i < n - 1; i += 2) {
        if ((A[i] > A[i-1] && A[i] > A[i+1]) || (A[i] < A[i-1] && A[i] < A[i+1])) {
            continue;
        } else {
            operations++;
            if (A[i-1] > A[i+1]) {
                swap(A[i], A[i-1]);
            } else {
                swap(A[i], A[i+1]);
            }
        }
    }

    cout << operations << endl;

    return 0;
}