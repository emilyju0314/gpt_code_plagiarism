#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    
    vector<int> cards(n);
    for(int i=0; i<n; i++) {
        cin >> cards[i];
    }
    
    long long totalSum = 0;
    
    for(int i=0; i<n; i++) {
        long long sum = cards[i];
        
        for(int j=0; j<n; j++) {
            if(i != j) {
                sum = (10 * sum + cards[j]) % MOD;
            }
        }
        
        totalSum = (totalSum + sum) % MOD;
    }
    
    cout << totalSum << endl;
    
    return 0;
}