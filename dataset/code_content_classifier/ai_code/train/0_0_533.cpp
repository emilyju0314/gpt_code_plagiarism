#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string n;
    cin >> n;

    vector<int> count(10, 0);
    int sum = 0, zeroCount = 0;

    for (char c : n) {
        int digit = c - '0';
        count[digit]++;
        if (digit == 0) {
            zeroCount++;
        }
        sum += digit;
    }

    // If sum is already divisible by 10, we can just print the number twice
    if (sum % 10 == 0) {
        cout << n << endl;
        cout << n << endl;
    } else {
        // Find the digit that can be changed to make the sum end with the maximum number of zeroes
        int changeDigit;
        for (int i = 0; i < 10; i++) {
            if ((sum - i) % 10 == 0) {
                changeDigit = i;
                break;
            }
        }

        // Create the two permutations by changing the digit and multiplying it with the count
        string n1, n2;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < count[i]; j++) {
                if (i == changeDigit && count[i] > 1) {
                    n1 += (char)(i + '0');
                    n2 += (char)(i + '0');
                    count[i] -= 2;
                } else {
                    n1 += (char)(i + '0');
                    n2 += (char)(i + '0');
                    count[i]--;
                }
            }
        }

        // Print the two permutations
        cout << n1 << endl;
        cout << n2 << endl;
    }

    return 0;
}