#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;
    return (n * factorial(n-1)) % MOD;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> permutation(n);
    int unknown_count = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> permutation[i];
        if (permutation[i] == -1) unknown_count++;
    }
    
    int total_permutations = factorial(n) / (factorial(unknown_count) * factorial(n - unknown_count));
    
    cout << total_permutations % MOD << endl;
    
    return 0;
}