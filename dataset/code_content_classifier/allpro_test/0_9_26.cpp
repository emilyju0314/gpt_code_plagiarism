#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

// Function to calculate the number of permutations modulo 1000000007
long long countPermutations(int n) {
    long long res = 1;
    for (int i = 1; i <= n; i++) {
        res = (res * i) % MOD;
    }
    return res;
}

int main() {
    int t;
    cin >> t;

    vector<int> testCases(t);
    for (int i = 0; i < t; i++) {
        cin >> testCases[i];
    }

    for (int i = 0; i < t; i++) {
        int n = testCases[i];
        long long res = countPermutations(2*n);
        cout << res << endl;
    }

    return 0;
}