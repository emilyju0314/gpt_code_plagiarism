#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int count = 0;
    int ones = 0;
    int zeroes = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            ones++;
        } else {
            zeroes++;
        }
    }

    count = max(ones, zeroes);
    if (ones == 0 || zeroes == 0) {
        cout << count << endl;
    } else {
        cout << count + 1 << endl;
    }

    return 0;
}