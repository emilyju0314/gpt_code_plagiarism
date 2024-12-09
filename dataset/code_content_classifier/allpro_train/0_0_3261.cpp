#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, p;
    cin >> N >> p;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int maxScore = 0;
    int prefixSum = 0;
    for (int i = 0; i < N - 1; i++) {
        prefixSum = (prefixSum + A[i]) % p;
        int suffixSum = 0;
        for (int j = i + 1; j < N; j++) {
            suffixSum = (suffixSum + A[j]) % p;
            maxScore = max(maxScore, (prefixSum + suffixSum) % p);
        }
    }

    cout << maxScore << endl;

    return 0;
}