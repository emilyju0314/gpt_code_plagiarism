#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    unordered_map<int, int> count;
    count[0] = 1;
    
    int xor_sum = 0;
    long long result = 0;
    
    for(int i=0; i<n; i++) {
        xor_sum ^= a[i];
        
        for(int j=0; (1 << j) <= xor_sum; j++) {
            result += count[xor_sum ^ (1 << j)];
        }
        
        count[xor_sum]++;
    }
    
    cout << result << endl;
    
    return 0;
}