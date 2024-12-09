#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Find all divisors of n
    vector<int> divisors;
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            divisors.push_back(i);
            if(i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }

    // Find the greatest beautiful divisor
    int greatest_beautiful_divisor = 1;
    for(int divisor : divisors) {
        bool is_beautiful = true;
        for(int k = 1; k * k < divisor; k++) {
            if((2*k - 1) * (2*k - 1) == divisor) {
                is_beautiful = false;
                break;
            }
        }
        if(is_beautiful && divisor > greatest_beautiful_divisor) {
            greatest_beautiful_divisor = divisor;
        }
    }

    cout << greatest_beautiful_divisor << endl;

    return 0;
}