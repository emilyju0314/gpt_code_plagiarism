#include <iostream>
#include <string>

using namespace std;

char keyboard[3][11] = {
    "qwertyuiop",
    "asdfghjkl;",
    "zxcvbnm,./"
};

int main() {
    char direction;
    string sequence;

    cin >> direction >> sequence;

    int shift = (direction == 'L') ? 1 : -1;

    string output = "";
    for (char c : sequence) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 10; j++) {
                if (keyboard[i][j] == c) {
                    output += keyboard[i][j + shift];
                }
            }
        }
    }

    cout << output << endl;

    return 0;
}