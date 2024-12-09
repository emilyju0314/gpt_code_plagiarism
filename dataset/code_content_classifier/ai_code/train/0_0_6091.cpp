#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());

    int count = 0;
    while (true) {
        if (find(digits.begin(), digits.end(), 0) != digits.end()) {
            break;
        }
        
        int min_digit = *min_element(digits.begin(), digits.end());
        n -= min_digit;
        
        vector<int> new_digits;
        while (n > 0) {
            new_digits.push_back(n % 10);
            n /= 10;
        }
        digits = new_digits;
        
        count++;
    }

    cout << count << endl;

    return 0;
}