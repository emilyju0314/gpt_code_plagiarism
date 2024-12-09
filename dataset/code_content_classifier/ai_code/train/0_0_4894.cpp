#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isValidDate(int date) {
    return date >= 1000 && date <= 2011;
}

bool isNonDecreasing(int num) {
    string s = to_string(num);
    return is_sorted(s.begin(), s.end());
}

int main() {
    int n;
    cin >> n;

    vector<int> dates(n);
    for (int i = 0; i < n; i++) {
        cin >> dates[i];
    }

    vector<int> result(n);
    result[0] = dates[0];

    for (int i = 1; i < n; i++) {
        if (dates[i] < result[i - 1]) {
            string original = to_string(dates[i]);
            string changed = to_string(result[i - 1]);

            string temp = changed;
            for (int j = 0; j < 4; j++) {
                if (original[j] != changed[j]) {
                    temp[j] = original[j];
                    if (stoi(temp) >= 1000 && stoi(temp) <= 2011 && isNonDecreasing(stoi(temp))) {
                        result[i] = stoi(temp);
                        break;
                    } else {
                        temp[j] = changed[j]; // revert the change
                    }
                }
            }

            if (result[i] == 0) {
                cout << "No solution" << endl;
                return 0;
            }
        } else {
            result[i] = dates[i];
        }
    }

    for (int date : result) {
        cout << date << endl;
    }

    return 0;
}