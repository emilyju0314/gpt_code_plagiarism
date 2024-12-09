#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<long long> grade(N);
    for (int i = 0; i < K; i++) {
        grade[i] = 0;
    }

    for (int i = K; i < N; i++) {
        grade[i] = grade[i-1] * A[i];
    }

    for (int i = K; i < N; i++) {
        if (grade[i] > grade[i-1]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}