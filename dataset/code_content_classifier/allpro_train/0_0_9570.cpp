#include <iostream>
#include <string>

using namespace std;

int main() {
    int m, s;
    cin >> m >> s;

    string min_num, max_num;

    // handle edge cases
    if (s == 0 && m == 1) {
        cout << "0 0" << endl;
        return 0;
    }

    if (s == 0 || s > 9 * m) {
        cout << "-1 -1" << endl;
        return 0;
    }

    // construct the minimum number
    int remaining_sum = s;
    for (int i = 0; i < m; i++) {
        for (int digit = 0; digit <= 9; digit++) {
            if ((i > 0 || digit > 0 || (m == 1 && digit == 0)) && remaining_sum - digit <= 9 * (m - i - 1)) {
                min_num += to_string(digit);
                remaining_sum -= digit;
                break;
            }
        }
    }

    // construct the maximum number
    remaining_sum = s;
    for (int i = 0; i < m; i++) {
        for (int digit = 9; digit >= 0; digit--) {
            if (remaining_sum - digit >= 0) {
                max_num += to_string(digit);
                remaining_sum -= digit;
                break;
            }
        }
    }

    cout << min_num << " " << max_num << endl;

    return 0;
}