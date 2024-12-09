#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    long long press = 0;
    long long sum = 0;

    for (int i = N - 1; i >= 0; i--) {
        sum += A[i];
        if (sum % B[i] != 0) {
            press += B[i] - (sum % B[i]);
        }
    }

    cout << press << endl;

    return 0;
}