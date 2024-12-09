#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getPermutation(int n, long long k) {
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = i + 1;
    }
    
    for (int i = 1; i <= n; i++) { 
        long long factorial = 1;
        for (int j = 2; j <= i; j++) {
            // calculate factorial of i
            factorial *= j;
        }
        int index = k % factorial; // find the index of the element to swap
        k /= factorial; 
        // rotate result by index
        rotate(result.begin(), result.begin() + index, result.end()); 
    }
    
    return result;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    
    vector<int> result = getPermutation(n, k-1); // k-th permutation is k-1 in 0-based indexing
    
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}