#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        
        int i = 2;
        int count = 0;
        int sum = 0;
        
        while (count < n) {
            if (isPrime(i)) {
                sum += i;
                count++;
            }
            i++;
        }
        
        cout << sum << endl;
    }
    
    return 0;
}