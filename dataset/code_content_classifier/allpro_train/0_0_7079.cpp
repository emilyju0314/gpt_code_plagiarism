#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    long long result = 1;
    for (int i = 1; i < N; i++) {
        result = (result * i) % MOD;
    }

    cout << result << endl;

    return 0;
}