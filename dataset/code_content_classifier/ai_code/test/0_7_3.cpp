#include <iostream>
#include <string>
using namespace std;

int countPossibleIntegers(string s) {
    int count = 0;
    for (int i = 0; i < 100; i++) {
        string num = to_string(i);
        while (num.size() < s.size()) {
            num = "0" + num;
        }
        bool possible = true;
        int idx = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'X') {
                if (idx == 0) {
                    idx = num[j] - '0';
                } else {
                    if (num[j] - '0' != idx) {
                        possible = false;
                        break;
                    }
                }
            } else {
                if (s[j] != '_' && s[j] != num[j]) {
                    possible = false;
                    break;
                }
            }
        }
        if (possible && stoi(num) % 25 == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    string s;
    cin >> s;
    cout << countPossibleIntegers(s) << endl;
    return 0;
}