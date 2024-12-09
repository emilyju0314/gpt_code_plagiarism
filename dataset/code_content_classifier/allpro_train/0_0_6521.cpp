#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int main() {
    int x;
    cin >> x;

    set<int> divisors;
    for(int i = 1; i <= sqrt(x); i++) {
        if(x % i == 0) {
            divisors.insert(i);
            divisors.insert(x / i);
        }
    }

    set<int> commonDigits;
    while(x > 0) {
        commonDigits.insert(x % 10);
        x /= 10;
    }

    int count = 0;
    for(int d : divisors) {
        int temp = d;
        while(temp > 0) {
            if(commonDigits.count(temp % 10) > 0) {
                count++;
                break;
            }
            temp /= 10;
        }
    }

    cout << count << endl;

    return 0;
}