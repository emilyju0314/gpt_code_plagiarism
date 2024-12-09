#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int countDivisibleBy25(string s) {
    int count = 0;

    for (int i = 0; i <= 99; i++) {
        string num = to_string(i);
        if (s.length() == num.length() && checkDivisibility(s, num)) {
            count++;
        }
    }

    return count;
}

bool checkDivisibility(string s, string num) {
    int index_s = s.length() - 1;
    int index_num = num.length() - 1;

    while (index_s >= 0 && index_num >= 0) {
        if (s[index_s] == 'X' && s[index_s] != num[index_num]) {
            return false;
        }
        if (s[index_s] != 'X' && s[index_s] != num[index_num]) {
            return false;
        }

        index_s--;
        index_num--;
    }

    return true;
}

int main() {
    string s;
    cin >> s;

    int result = countDivisibleBy25(s);
    cout << result << endl;

    return 0;
}