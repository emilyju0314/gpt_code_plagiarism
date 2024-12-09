#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string A, B;
    int K;
    cin >> A >> B >> K;
    
    int n = max(A.size(), B.size());
    A = string(n - A.size(), '0') + A;
    B = string(n - B.size(), '0') + B;
    
    int result = 0;
    for (int k = 0; k <= K; ++k) {
        int carry = 0, curr = 0;
        for (int i = n - 1; i >= 0; --i) {
            int diff = (A[i] - '0') - carry - (B[i] - '0');
            if (diff < 0) {
                diff += 10;
                carry = 1;
            } else {
                carry = 0;
            }
            curr = curr * 10 + diff;
        }
        result = max(result, curr);
        
        // Permute B for the next iteration
        next_permutation(B.begin(), B.end());
    }
    
    cout << result << endl;
    
    return 0;
}