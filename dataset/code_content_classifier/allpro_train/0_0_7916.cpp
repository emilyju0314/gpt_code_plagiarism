#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

void multiplyMatrix(vector<vector<long long>>& a, vector<vector<long long>>& b) {
    vector<vector<long long>> res(2, vector<long long>(2, 0));
    
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    
    a = res;
}

void powerMatrix(vector<vector<long long>>& base, long long exp) {
    vector<vector<long long>> res = {{1, 0}, {0, 1}}; // identity matrix
    
    while(exp > 0) {
        if(exp % 2 == 1) {
            multiplyMatrix(res, base);
        }
        multiplyMatrix(base, base);
        exp /= 2;
    }
    
    base = res;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<long long>> transformationMatrix = {{1, 1}, {1, 0}};
    powerMatrix(transformationMatrix, k);
    
    vector<long long> initial = {1, 1}; // F(1) = 1, F(2) = 2
    vector<vector<long long>> result = {{1, 0}, {0, 1}}; // identity matrix
    
    for(int i = 0; i < n; i++) {
        result[0][0] = (result[0][0] + initial[1]) % MOD;
        multiplyMatrix(initial, transformationMatrix);
    }
    
    cout << result[0][0] << endl;
    
    return 0;
} 

// You can use the above code to calculate the sum of the first n elements of the sequence Ai(k) modulo 1000000007.