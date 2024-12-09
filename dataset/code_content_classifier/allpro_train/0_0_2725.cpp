#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isDivisibleBy8(string num) {
    for (int i = 0; i < num.size(); i++) {
        for (int j = i + 1; j < num.size(); j++) {
            for (int k = j + 1; k < num.size(); k++) {
                if ((num[i] - '0') * 100 + (num[j] - '0') * 10 + (num[k] - '0') % 8 == 0) {
                    cout << "YES" << endl;
                    cout << num[i] << num[j] << num[k] << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    string num;
    cin >> num;

    if (isDivisibleBy8(num)) {
        return 0;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}