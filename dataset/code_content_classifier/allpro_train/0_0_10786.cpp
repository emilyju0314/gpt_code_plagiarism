#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int count = 0;
    string response;
    
    for (int i = 2; i <= 100; ++i) {
        cout << i << endl << flush;
        cin >> response;
        if (response == "yes") {
            count++;
        }
    }
    
    if (isPrime(count)) {
        cout << "prime" << endl << flush;
    } else {
        cout << "composite" << endl << flush;
    }
    
    return 0;
}