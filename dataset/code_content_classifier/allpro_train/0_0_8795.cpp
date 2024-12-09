#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int kr, kb, ky, kg;
    kr = kb = ky = kg = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'R' && (i % 4 == 0 || i % 4 == 3)) {
            kr += (s[i] == '!');
        }
        if (s[i] == 'B' && (i % 4 == 0 || i % 4 == 1)) {
            kb += (s[i] == '!');
        }
        if (s[i] == 'Y' && (i % 4 == 0 || i % 4 == 2)) {
            ky += (s[i] == '!');
        }
        if (s[i] == 'G' && (i % 4 == 0 || i % 4 == 1 || i % 4 == 2)) {
            kg += (s[i] == '!');
        }
    }

    cout << kr << " " << kb << " " << ky << " " << kg << endl;

    return 0;
}