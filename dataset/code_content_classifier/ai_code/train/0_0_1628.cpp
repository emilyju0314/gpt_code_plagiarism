#include <iostream>
#include <vector>

using namespace std;

long long sum_of_digits(long long n) {
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    long long N;
    cin >> N;

    // Find the maximum number with the same number of digits as N
    long long max_num = 1;
    while (max_num * 10 - 1 <= N) {
        max_num = max_num * 10 + 1;
    }

    // Calculate the sum of digits for the maximum number less than or equal to N
    long long max_sum = sum_of_digits(max_num);
    
    cout << max_sum << endl;

    return 0;
}