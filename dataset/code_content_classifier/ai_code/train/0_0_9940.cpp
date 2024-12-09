#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    string A, B, C;
    cin >> N >> A >> B >> C;

    int operations = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == B[i] && B[i] == C[i]) {
            continue;
        } 
        if (A[i] == B[i] || A[i] == C[i] || B[i] == C[i]) {
            operations++;
        } else {
            operations += 2;
        }
    }

    cout << operations << endl;

    return 0;
}