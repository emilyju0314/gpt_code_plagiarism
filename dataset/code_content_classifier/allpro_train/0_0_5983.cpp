#include <iostream>
using namespace std;

bool isLucky(int num) {
    while(num > 0) {
        int digit = num % 10;
        if(digit != 4 && digit != 7) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int nextLuckyNumber(int num) {
    while(true) {
        num++;
        if(isLucky(num)) {
            return num;
        }
    }
}

int main() {
    int l, r;
    cin >> l >> r;

    long long sum = 0;
    for(int i = l; i <= r; i++) {
        sum += nextLuckyNumber(i);
    }

    cout << sum << endl;

    return 0;
}