#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> prefixSum(n+1, 0);
    for(int i = 0; i < n; i++) {
        prefixSum[i+1] = prefixSum[i] + (a[i] < x ? 1 : 0);
    }
    
    vector<int> count(n+1, 0);
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j <= n; j++) {
            count[j - i] = max(count[j - i], prefixSum[j] - prefixSum[i]);
        }
    }
    
    for(int i = 0; i <= n; i++) {
        cout << count[i] << " ";
    }
    
    return 0;
}