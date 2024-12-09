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

    long long operations = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] < A[i - 1]) {
            operations += A[i - 1] - A[i];
            A[i] = A[i - 1];
        }
    }

    cout << operations << endl;

    return 0;
}