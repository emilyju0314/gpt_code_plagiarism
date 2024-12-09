#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findPermutation(int n, long long k) {
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = i + 1;
    }
    
    for (int i = 1; i <= n; i++) {
        long long fact = 1;
        for (int j = 1; j < n-1; j++) {
            fact *= j;
        }
        
        int nextPos = (k - 1) / fact;
        int nextElement = result[nextPos];
        
        for (int j = nextPos; j > 0; j--) {
            result[j] = result[j-1];
        }
        
        result[0] = nextElement;
        k = (k - 1) % fact + 1;
        
        n--;
    }
    
    return result;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    
    vector<int> perm = findPermutation(n, k);
    
    for (int i = 0; i < n; i++) {
        cout << perm[i] << " ";
    }
    
    return 0;
}