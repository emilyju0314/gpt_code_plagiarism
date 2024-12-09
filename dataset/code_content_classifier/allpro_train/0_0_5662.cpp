#include <iostream>
#include <string>

using namespace std;

int main() {
    string borze;
    cin >> borze;

    string ternary = "";
    for (int i = 0; i < borze.length(); i++) {
        if (borze[i] == '.') {
            ternary += "0";
        } else if (borze[i] == '-') {
            if (borze[i + 1] == '.') {
                ternary += "1";
                i++;
            } else {
                ternary += "2";
                i++;
            }
        }
    }

    cout << ternary << endl;

    return 0;
}