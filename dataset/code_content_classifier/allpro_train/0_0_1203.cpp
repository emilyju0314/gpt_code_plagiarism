#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<long long> left(N), right(N);

    for(int i = 0; i < N; i++) {
        if(A[i] > N-1-i || A[i] < abs(i-N+1)) {
            cout << 0 << endl;
            return 0;
        }
        left[i] = max(0, i - A[i]);
        right[i] = min(N-1, i + A[i]);
    }

    long long result = 1;
    for(int i = 0; i < N; i++) {
        result = (result * (right[i] - left[i] + 1)) % MOD;
    }

    cout << result << endl;

    return 0;
}