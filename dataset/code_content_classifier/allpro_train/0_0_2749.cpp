#include <iostream>
#include <vector>
#include <cmath>

#define MOD 1000000007

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int inversions = 0;

    for(int i = 0; i < (1 << Q); i++) {
        vector<int> B = A;
        for(int j = 0; j < Q; j++) {
            if((i & (1 << j)) > 0) {
                swap(B[j], B[j + 1]);
            }
        }

        for(int j = 0; j < N; j++) {
            for(int k = j + 1; k < N; k++) {
                if(B[j] > B[k]) {
                    inversions++;
                }
            }
        }
    }

    cout << inversions % MOD << endl;

    return 0;
}