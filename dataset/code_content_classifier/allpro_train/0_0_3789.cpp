#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    vector<int> F(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> F[i];
    }

    long long min_score = LLONG_MAX;

    // Iterate through all possible number of dishes assigned to each member
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            // Calculate the total consumption coefficient by applying training
            long long total_A = 0;
            for(int k = 0; k < N; k++) {
                total_A += max(0, A[k] - i);
            }

            // Calculate the total difficulty of dishes assigned to members
            long long total_F = 0;
            for(int k = 0; k < N; k++) {
                total_F += max(0, F[k] - j);
            }

            // Check if the total consumption coefficient and total difficulty can be achieved with the given number of training sets
            if(total_A * total_F <= K) {
                min_score = min(min_score, max(total_A, total_F));
            }
        }
    }

    cout << min_score << endl;

    return 0;
}