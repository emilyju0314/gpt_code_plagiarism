#include <iostream>
#include <string>

using namespace std;

int sumOfDigits(long long num) {
    int sum = 0;
    while(num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    long long x;
    cin >> x;

    string result = to_string(x);
    int maxSum = sumOfDigits(x);

    for (int i = 1; i <= result.length(); i++) {
        if (result[result.length() - i] != '0') {
            result[result.length() - i] = '9';
            long long newNum = stoll(result);
            if (sumOfDigits(newNum) > maxSum || (sumOfDigits(newNum) == maxSum && newNum > x)) {
                x = newNum;
                maxSum = sumOfDigits(newNum);
            }
        }
    }

    cout << x << endl;

    return 0;
}