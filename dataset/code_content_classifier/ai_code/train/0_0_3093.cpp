#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }

    long long sum_A = 0, sum_B = 0;
    for(int i = 0; i < N; i++) {
        sum_A += A[i];
        sum_B += B[i];
    }

    if(sum_B < sum_A) {
        cout << -1 << endl;
    } else {
        int operations = 0;
        for(int i = 0; i < N; i++) {
            int diff = B[i] - A[i];
            if(diff < 0) {
                cout << -1 << endl;
                return 0;
            }
            if(i > 0 && B[i-1] > A[i-1] && diff != (B[i-1] - A[i-1])) {
                operations += 1;
            }
        }

        cout << operations << endl;
    }

    return 0;
}