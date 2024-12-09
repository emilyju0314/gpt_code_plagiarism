#include <iostream>
#include <cmath>

using namespace std;

int sumOfDigitsInBinary(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 2;
        num = num / 2;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    
    int maxSum = 0;
    for (int i = 0; i <= N; i++) {
        int sum = sumOfDigitsInBinary(i);
        if (sum > maxSum) {
            maxSum = sum;
        }
    }
    
    cout << maxSum << endl;
    
    return 0;
}