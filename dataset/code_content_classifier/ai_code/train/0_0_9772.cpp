#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

long long factorial(int n) {
    long long res = 1;
    for (int i = 1; i <= n; i++) {
        res = (res * i) % MOD;
    }
    return res;
}

int main() {
    int N;
    cin >> N;

    vector<int> d(N);
    int sum_d = 0;
    for (int i = 0; i < N; i++) {
        cin >> d[i];
        sum_d += d[i];
    }

    long long answer = factorial(N - 2);
    for (int i = 0; i < N; i++) {
        answer = (answer * factorial(d[i] - 1)) % MOD;
    }

    cout << answer << endl;

    return 0;
}