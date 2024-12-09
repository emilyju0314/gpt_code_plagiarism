#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string text;
    getline(cin, text);
    cin >> n;

    int numMessages = 1;
    int currentLength = 0;
    bool impossible = false;

    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            if (currentLength + 1 > n) {
                numMessages++;
                currentLength = 0;
            }
        } else if (text[i] != ' ') {
            currentLength++;
        }

        if (currentLength > n) {
            impossible = true;
            break;
        }
    }

    if (impossible) {
        cout << "Impossible" << endl;
    } else {
        cout << numMessages << endl;
    }

    return 0;
}