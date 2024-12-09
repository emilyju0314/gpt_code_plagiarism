#include <iostream>
#include <cmath>

using namespace std;

string conciseNotation(long long n) {
    if(n == 0) {
        return "0";
    }

    for(int exp = 10; exp >= 2; exp--) {
        long long power = pow(10, exp);
        if(n % power == 0) {
            long long multiplier = n / power;
            if(multiplier > 1) {
                return to_string(multiplier) + "*" + "10^" + to_string(exp);
            } else {
                return "10^" + to_string(exp);
            }
        }
    }

    for(int exp = 9; exp >= 2; exp--) {
        long long power = pow(10, exp);
        if(n % power == 0) {
            long long multiplier = n / power;
            if(multiplier > 1) {
                return to_string(multiplier) + "*" + "10^" + to_string(exp);
            } else {
                return "10^" + to_string(exp);
            }
        }
    }

    return to_string(n);
}

int main() {
    long long n;
    cin >> n;
    
    string result = conciseNotation(n);
    cout << result << endl;

    return 0;
}