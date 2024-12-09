#include <iostream>

using namespace std;

// Function to calculate the smallest possible number of resistors needed
long long calculateResistors(long long a, long long b) {
    long long result = 0;
    
    while(b != 0) {
        result += a / b;
        a = a % b;
        swap(a, b);
    }
    
    return result;
}

int main() {
    long long a, b;
    cin >> a >> b;
    
    cout << calculateResistors(a, b) << endl;
    
    return 0;
}