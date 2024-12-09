#include <iostream>
#include <string>

int getDigitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int N, A, B;
    std::cin >> N >> A >> B;
    
    int total = 0;
    for (int i = 1; i <= N; i++) {
        int digitSum = getDigitSum(i);
        if (digitSum >= A && digitSum <= B) {
            total += i;
        }
    }
    
    std::cout << total << std::endl;
    
    return 0;
}