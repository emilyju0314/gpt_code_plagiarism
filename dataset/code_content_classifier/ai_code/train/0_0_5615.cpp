#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_palindrome_possible(vector<int>& A, int N) {
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != A[A.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    if (is_palindrome_possible(A, N)) {
        cout << "Impossible" << endl;
    } else {
        cout << N << endl;
        cout << N << endl;
        for (int i = 1; i <= N; i++) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}