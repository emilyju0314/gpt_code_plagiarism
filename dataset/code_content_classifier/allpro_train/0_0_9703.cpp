#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int countZeroAndSubsets(vector<int>& a) {
    int n = a.size();
    int result = 1;
    for (int i = 0; i < n; i++) {
        result = (result * 2) % MOD;
    }
    return (result - 1 + MOD) % MOD;
}

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << countZeroAndSubsets(a) << endl;

    return 0;
}