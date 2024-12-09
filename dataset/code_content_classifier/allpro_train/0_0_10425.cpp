#include <iostream>
#include <string>

using namespace std;

int main() {
    string hint;
    cin >> hint;

    long long count = 1; // Initialize count to 1

    for (int i = 0; i < hint.size(); i++) {
        if (hint[i] == '?') {
            if (i == 0) {
                count *= 9; // 9 possible values for the first digit if it can't be 0
            } else {
                count *= 10; // 10 possible values for any other digit
            }
        } else if (hint[i] >= '0' && hint[i] <= '9') {
            count *= 1; // Digit is fixed, so only 1 possible value
        } else {
            if (hint[0] == hint[i]) {
                count *= 10; // Same letter as the first letter means 10 possible values
            } else {
                count *= 9; // Distinct letter than the first letter means 9 possible values
            }
        }
    }

    cout << count << endl;

    return 0;
}