#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;

vector<long long> prefixXor(vector<long long>& nums) {
    int n = nums.size();
    vector<long long> prefixXor(n);
    prefixXor[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefixXor[i] = prefixXor[i - 1] ^ nums[i];
    }
    return prefixXor;
}

int main() {
    int N;
    cin >> N;
    
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    vector<long long> prefix = prefixXor(A);
    
    long long res = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            res = (res + (prefix[i] ^ prefix[j])) % MOD;
        }
    }
    
    cout << res << endl;
    
    return 0;
}