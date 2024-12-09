#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string question;
    getline(cin, question);

    char lastLetter;
    for (int i = question.length() - 2; i >= 0; i--) {
        if (isalpha(question[i])) {
            lastLetter = tolower(question[i]);
            break;
        }
    }

    if (lastLetter == 'a' || lastLetter == 'e' || lastLetter == 'i' || lastLetter == 'o' || lastLetter == 'u' || lastLetter == 'y') {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}