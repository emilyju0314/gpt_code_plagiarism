#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    // Start with 5 raised to power 1
    long long result = 5;
    
    // Multiply by 5 for n-1 times
    for(int i=1; i<n; i++) {
        result = (result * 5) % 100;
    }
    
    cout << result;
    
    return 0;
}