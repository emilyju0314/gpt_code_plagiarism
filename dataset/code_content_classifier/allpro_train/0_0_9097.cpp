#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

bool isBeautifulMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Check all elements are integers between 1 and n
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < 1 || matrix[i][j] > n) {
                return false;
            }
        }
    }
    
    // Check each row has all distinct elements
    for (int i = 0; i < n; i++) {
        vector<bool> used(n + 1, false);
        for (int j = 0; j < n; j++) {
            if (used[matrix[i][j]]) {
                return false;
            }
            used[matrix[i][j]] = true;
        }
    }
    
    // Check each pair of vertically adjacent elements are different
    for (int j = 0; j < n; j++) {
        vector<bool> used(n + 1, false);
        for (int i = 0; i < n; i++) {
            if (used[matrix[i][j]]) {
                return false;
            }
            used[matrix[i][j]] = true;
        }
    }
    
    return true;
}

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

int inversionCount(vector<int>& permutation) {
    int n = permutation.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (permutation[i] > permutation[j]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    if (!isBeautifulMatrix(matrix)) {
        cout << "Invalid input. Matrix is not beautiful." << endl;
        return 0;
    }
    
    vector<int> permutation(n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            permutation[i * n + j] = matrix[i][j];
        }
    }
    
    int rarity = inversionCount(permutation);
    cout << rarity % MOD << endl;
    
    return 0;
}