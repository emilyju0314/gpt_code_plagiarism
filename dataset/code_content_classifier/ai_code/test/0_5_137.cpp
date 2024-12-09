#include <iostream>
using namespace std;

// Function to convert a decimal number to its binary representation without leading zeros
string toBinaryWithoutLeadingZeros(long long n) {
    string binary = "";
    while (n > 0) {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    return binary;
}

// Function to check if x can be turned into y after a certain number of operations
bool canBeTurned(long long x, long long y) {
    if (x == y) {
        return true;
    } else if (x > y) {
        return false;
    } else if ((y % 2 == 1) || (y % 2 == 0 && x % 2 == 1)) {
        return false;
    } else {
        string binaryX = toBinaryWithoutLeadingZeros(x);
        string binaryY = toBinaryWithoutLeadingZeros(y);
        
        int i = binaryX.length() - 1;
        int j = binaryY.length() - 1;
        
        while (j >= 0) {
            if (i < 0 || binaryX[i] != binaryY[j]) {
                return false;
            }
            i--;
            j--;
        }
        
        return true;
    }
}

int main() {
    long long x, y;
    cin >> x >> y;
    
    if (canBeTurned(x, y)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}