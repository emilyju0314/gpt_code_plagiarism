#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinOperations(long long n) {
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    int minOperations = 0;
    while (*max_element(digits.begin(), digits.end()) != 0) {
        int minDigit = *min_element(digits.begin(), digits.end());
        n -= minDigit;
        digits.clear();
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        minOperations++;
    }
    return minOperations;
}

int main() {
    long long n;
    cin >> n;
    cout << findMinOperations(n) << endl;
    return 0;
}