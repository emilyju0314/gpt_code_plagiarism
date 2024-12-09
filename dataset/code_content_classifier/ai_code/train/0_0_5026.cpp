#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int row = 1, col = 1;
    for(char c : s) {
        cout << row << " " << col << endl;
        if(c == '0') {
            cout << row << " " << col + 1 << endl;
            col += 2;
        } else {
            cout << row + 1 << " " << col << endl;
            row += 2;
        }
    }

    return 0;
}