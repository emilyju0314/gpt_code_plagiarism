#include <iostream>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int N, M;
        cin >> N >> M;

        if (N == 0 && M == 0) {
            break;
        }

        vector<int> coins(N);
        for (int i = 0; i < N; i++) {
            cin >> coins[i];
        }

        // Calculate the minimum number of operations
        int numOperations = 0;
        for (int i = N - 1; i >= 0; i--) {
            numOperations += M / coins[i];
            M %= coins[i];
        }

        cout << numOperations << endl;
    }

    return 0;
}