#include <iostream>
#include <set>
#include <string>

using namespace std;

int minKeyboardClicks(string text) {
    set<string> words;
    int clicks = 0;
    string currentWord = "";

    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ' || text[i] == '.' || text[i] == ',' || text[i] == '?' || text[i] == '!' || text[i] == '\'' || text[i] == '-') {
            words.insert(currentWord);
            currentWord = "";
            clicks++;
        } else {
            currentWord += text[i];
        }
    }

    clicks += words.size(); // each unique word requires one click

    return clicks;
}

int main() {
    string text;
    getline(cin, text);

    int minClicks = minKeyboardClicks(text);
    cout << minClicks << endl;

    return 0;
}