#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    cin >> word;

    bool allUpperCase = true;
    bool firstLowerCase = false;

    for (int i = 0; i < word.length(); i++) {
        if (islower(word[i])) {
            allUpperCase = false;
            if (i == 0) {
                firstLowerCase = true;
            }
        } else {
            if (i > 0) {
                firstLowerCase = false;
            }
        }
    }

    if (allUpperCase || firstLowerCase) {
        for (int i = 0; i < word.length(); i++) {
            if (islower(word[i])) {
                word[i] = toupper(word[i]);
            } else {
                word[i] = tolower(word[i]);
            }
        }
    }

    cout << word << endl;

    return 0;
}