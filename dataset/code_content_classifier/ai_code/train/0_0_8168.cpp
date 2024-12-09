#include <iostream>
#include <vector>

using namespace std;

// Function to check if a number is periodic
bool isPeriodic(long long num) {
    if (num == 0) return false;
    
    string binary = "";
    while (num > 0) {
        binary = to_string(num % 2) + binary;
        num /= 2;
    }
    
    int n = binary.length();
    
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            bool isPeriodic = true;
            for (int j = i; j < n; j++) {
                if (binary[j] != binary[j-i]) {
                    isPeriodic = false;
                    break;
                }
            }
            if (isPeriodic) return true;
        }
    }
    
    return false;
}

int main() {
    long long l, r;
    cin >> l >> r;
    
    int count = 0;
    for (long long i = l; i <= r; i++) {
        if (isPeriodic(i)) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}