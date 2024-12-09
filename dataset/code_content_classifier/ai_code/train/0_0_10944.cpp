#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> absurdity(n);
    for (int i = 0; i < n; i++) {
        cin >> absurdity[i];
    }
    
    int maxTotalAbsurdity = 0;
    int a = 0, b = 0;
    vector<int> prefixSum(n+1, 0);
    
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i-1] + absurdity[i-1];
    }
    
    for (int i = 0; i <= n-k; i++) {
        int totalAbsurdity = prefixSum[i+k] - prefixSum[i];
        
        if (totalAbsurdity > maxTotalAbsurdity) {
            maxTotalAbsurdity = totalAbsurdity;
            a = i+1;
            b = i+1+k;
        }
    }
    
    cout << a << " " << b << endl;
    
    return 0;
}