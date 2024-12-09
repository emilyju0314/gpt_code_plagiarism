#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> roundNumbers;
        int powerOf10 = 1;

        while (n > 0) {
            int digit = n % 10;
            if (digit > 0) {
                roundNumbers.push_back(digit * powerOf10);
            }
            n /= 10;
            powerOf10 *= 10;
        }

        reverse(roundNumbers.begin(), roundNumbers.end());

        cout << roundNumbers.size() << endl;
        for (int i = 0; i < roundNumbers.size(); i++) {
            cout << roundNumbers[i] << " ";
        }
        cout << endl;
    }

    return 0;
}