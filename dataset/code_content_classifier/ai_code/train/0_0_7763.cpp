#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int fast_max(int n, int k) {   
    int ans = 0;  
    int offset = 0;  
    for (int i = 0; i < n; ++i) {  
        if (ans < i + 1) {  
            ans = i + 1;  
            offset = 0;  
        } else {  
            offset = offset + 1;  
            if (offset == k)  
                return ans;  
        }  
    }  
    return ans;  
}

int main() {
    int n, k;
    cin >> n >> k;

    long long result = 0;
    long long factorial = 1;

    for (int i = 1; i <= n; ++i) {
        factorial = (factorial * i) % MOD;
    }

    for (int i = 1; i <= n; ++i) {
        if (fast_max(n, k) != n) {
            result = (result + 1) % MOD;
        }
        next_permutation(arr, arr + n);
    }

    cout << result << endl;

    return 0;
}