#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string n;
    cin >> n;

    int sum = 0;
    vector<int> count(3);

    for (char c : n) {
        int digit = c - '0';
        sum += digit;
        count[digit % 3]++;
    }

    sum %= 3;

    if (sum == 0) {
        cout << n << endl;
    } else {
        bool found = false;

        for (int i = sum; i < 3; i+=3) {
            if (count[i] > 0) {
                found = true;

                for (char c : n) {
                    int digit = c - '0';

                    if (((digit % 3) == i) && count[i] > 0) {
                        count[i]--;
                    } else {
                        cout << digit;
                    }
                }

                break;
            }
        }

        if (!found) {
            int target = (sum == 1) ? 2 : 1;
            int removed = 0;

            for (int i = n.size() - 1; i >= 0; i--) {
                int digit = n[i] - '0';

                if ((digit % 3) == target && removed < 2) {
                    removed++;
                } else {
                    cout << digit;
                }
            }
        }

        cout << endl;
    }

    return 0;
}