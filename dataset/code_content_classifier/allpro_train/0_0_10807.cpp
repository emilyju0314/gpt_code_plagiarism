#include <iostream>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;

    // Calculate the total number of sequences
    long long X = 1;
    for(int i = 0; i < N; i++) {
        X *= K;
    }

    // Find the (X/2)-th lexicographically smallest sequence
    long long target = X / 2;

    for(int i = 0; i < N; i++) {
        long long blockSize = X / K;
        int num = target / blockSize;
        target %= blockSize;
        cout << num+1 << " ";
        K--;
        X = blockSize;
    }

    cout << endl;

    return 0;
}