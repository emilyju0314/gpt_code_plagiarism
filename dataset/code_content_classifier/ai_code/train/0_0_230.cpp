#include <iostream>
#include <string>

using namespace std;

bool isKeyenceString(string s) {
    string key = "keyence";
    int len = s.length();

    for(int i = 0; i < len; i++) {
        string left = s.substr(0, i);
        string right = s.substr(i + (len - 7));

        if((left + right) == key) {
            return true;
        }
    }

    return false;
}

int main() {
    string s;
    cin >> s;

    if(isKeyenceString(s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}