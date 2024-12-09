#include <iostream>
#include <string>

using namespace std;

int main() {
    string xmlText;
    cin >> xmlText;

    int level = 0;
    for (int i = 0; i < xmlText.length(); i++) {
        if (xmlText[i] == '<' && xmlText[i + 1] != '/') {
            for (int j = 0; j < 2 * level; j++) {
                cout << " ";
            }
            cout << "<" << xmlText[i + 1] << ">" << endl;
            level++;
        } else if (xmlText[i] == '<' && xmlText[i + 1] == '/') {
            level--;
            for (int j = 0; j < 2 * level; j++) {
                cout << " ";
            }
            cout << "</" << xmlText[i + 2] << ">" << endl;
        }
    }

    return 0;
}