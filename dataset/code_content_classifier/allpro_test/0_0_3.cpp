#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int count = 0;

    for (int i = 0; i < 100; i++) {
        string num = to_string(i);
        while (num.length() < s.length()) {
            num = "0" + num;
        }

        bool valid = true;
        for (int j = 0; j < s.length(); j++) {
            if ((s[j] != num[j]) && (s[j] != '_')) {
                valid = false;
                break;
            }
        }

        if (valid) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}