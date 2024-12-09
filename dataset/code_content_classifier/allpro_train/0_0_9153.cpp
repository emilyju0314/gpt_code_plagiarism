#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int k = 0; k < K; k++) {
        vector<int> B(N+1, 0);
        for (int i = 0; i < N; i++) {
            int left = max(0, i - A[i]);
            int right = min(N, i + A[i] + 1);
            B[left]++;
            B[right]--;
        }

        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += B[i];
            A[i] = sum;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}