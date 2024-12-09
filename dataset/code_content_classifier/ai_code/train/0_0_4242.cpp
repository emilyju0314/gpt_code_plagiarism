#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] <= X && B[i] >= X) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}