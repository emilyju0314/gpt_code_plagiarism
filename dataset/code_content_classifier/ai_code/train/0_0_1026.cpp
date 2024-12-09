#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = (fact * i) % MOD;
    }
    return fact;
}

int main() {
    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    vector<int> used(N, false);
    long long sum = 0;
    
    for (int i = 0; i < N; i++) {
        if (P[i] != 0) {
            if (used[P[i] - 1]) {
                cout << "Invalid input!" << endl;
                return 0;
            }
            used[P[i] - 1] = true;
        } else {
            for (int j = 0; j < N; j++) {
                if (!used[j]) {
                    sum = (sum + (factorial(N - i - 1) * (j + 1)) % MOD) % MOD;
                }
            }
        }
    }

    cout << sum + 1 << endl;

    return 0;
}