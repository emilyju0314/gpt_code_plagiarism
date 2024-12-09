#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    size_t pos1 = s.find("AB");
    size_t pos2 = s.find("BA", pos1 + 2);
    size_t pos3 = s.find("BA");
    size_t pos4 = s.find("AB", pos3 + 2);

    if ((pos1 != string::npos && pos2 != string::npos) || (pos3 != string::npos && pos4 != string::npos)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}