#include <iostream>
#include <string>

using namespace std;

int main() {
    string t;
    cin >> t;

    int count_a = 0;
    for(char c : t) {
        if(c == 'a') {
            count_a++;
        }
    }

    if(count_a > t.length() / 2) {
        cout << ":(\n";
    } else {
        int len_s = (t.length() - count_a) * 2;
        string s = t.substr(0, len_s);

        bool valid = true;
        for(int i = 0; i < s.length() / 2; i++) {
            if(s[i] != s[i + s.length() / 2]) {
                valid = false;
                break;
            }
        }

        if(valid) {
            cout << s << endl;
        } else {
            cout << ":(\n";
        }
    }

    return 0;
}