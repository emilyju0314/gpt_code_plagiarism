#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    vector<int> result(N);

    // Initialize result with infinity
    for (int i = 0; i < N; i++) {
        result[i] = INT_MAX;
    }

    // Update result with the minimum cost to convert each tree to Sugi
    for (int i = 0; i < N; i++) {
        result[i] = min(result[i], abs(A[0] - A[i])); // Heaven cost to convert to Sugi
        result[i] = min(result[i], abs(B[0] - B[i])); // Demon cost to convert to Sugi
    }

    // Output the result
    for (int i = 0; i < N; i++) {
        cout << result[i] << endl;
    }

    return 0;
}