#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    cin >> s;
    string x_str;
    cin >> x_str;

    long long x = stoll(x_str);

    unordered_map<long long, int> pos;

    for (int i = 1; i < s.length(); ++i) {
        int num1 = stoi(s.substr(0, i));
        int num2 = stoi(s.substr(i));

        if (num1 + num2 == x && s[i] != '0') {
            cout << "1 " << i << endl;
            cout << i + 1 << " " << s.length() << endl;
            break;
        }
    }

    return 0;
}