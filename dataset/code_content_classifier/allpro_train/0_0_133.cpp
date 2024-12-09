#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int l, r;
    cin >> l >> r;
    
    unordered_map<int, int> divisorCount;
    
    for(int i = l; i <= r; i++) {
        for(int j = 2; j*j <= i; j++) {
            if(i % j == 0) {
                divisorCount[j]++;
                if(j != i/j) {  // Check if j is not the square root of i
                    divisorCount[i/j]++;
                }
            }
        }
    }
    
    int maxCount = 0;
    int maxDivisor = 2;  // Default answer if no other divisor found
    for(auto it : divisorCount) {
        if(it.second > maxCount) {
            maxCount = it.second;
            maxDivisor = it.first;
        }
    }
    
    cout << maxDivisor << endl;
    
    return 0;
}