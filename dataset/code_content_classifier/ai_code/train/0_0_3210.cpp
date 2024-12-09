#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n < 10) {
        cout << n << endl;
    } else {
        vector<int> digits;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        reverse(digits.begin(), digits.end());

        int firstNonNineIdx = 0;
        while (firstNonNineIdx < digits.size() && digits[firstNonNineIdx] == 9) {
            firstNonNineIdx++;
        }

        if (firstNonNineIdx == digits.size()) {
            cout << 1;
            for (int i = 0; i < digits.size() - 1; i++) {
                cout << 9;
            }
        } else {
            digits[firstNonNineIdx]--;
            for (int i = firstNonNineIdx + 1; i < digits.size(); i++) {
                digits[i] = 9;
            }
        }

        long long product = 1;
        for (int digit : digits) {
            product *= digit;
        }

        cout << product << endl;
    }

    return 0;
}