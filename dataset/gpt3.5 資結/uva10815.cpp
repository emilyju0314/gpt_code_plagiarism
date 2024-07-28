#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string word, text;
    set<string> dictionary;

    while (cin >> word) {
        for (char& c : word) {
            if (isalpha(c)) {
                c = tolower(c);
            }
            else {
                c = ' ';
            }
        }

        text += word + ' ';
    }

    while (!text.empty()) {
        string word;
        int pos = text.find(' ');

        if (pos != string::npos) {
            word = text.substr(0, pos);
            text = text.substr(pos + 1);
        }
        else {
            word = text;
            text = "";
        }

        if (!word.empty()) {
            dictionary.insert(word);
        }
    }

    for (const string& word : dictionary) {
        cout << word << endl;
    }

    return 0;
}