#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, C;
    cin >> N >> M >> C;

    vector<int> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        vector<int> A(M);
        int sum = 0;
        for (int j = 0; j < M; j++) {
            cin >> A[j];
            sum += A[j] * B[j];
        }
        sum += C;

        if (sum > 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}