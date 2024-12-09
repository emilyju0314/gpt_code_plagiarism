#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> dictionary;

bool isValidWord(string word) {
    for (string validWord : dictionary) {
        if (validWord == word) {
            return true;
        }
    }
    return false;
}

void generateWords(string sequence, string currentWord, int currentIndex) {
    if (currentIndex == sequence.size()) {
        if (isValidWord(currentWord)) {
            cout << currentWord << "." << endl;
        }
        return;
    }

    int button = sequence[currentIndex] - '0';
    string letters;
    switch(button) {
        case 2:
            letters = "abc";
            break;
        case 3:
            letters = "def";
            break;
        case 4:
            letters = "ghi";
            break;
        case 5:
            letters = "jkl";
            break;
        case 6:
            letters = "mno";
            break;
        case 7:
            letters = "pqrs";
            break;
        case 8:
            letters = "tuv";
            break;
        case 9:
            letters = "wxyz";
            break;
    }

    for (char letter : letters) {
        generateWords(sequence, currentWord + letter, currentIndex + 1);
    }
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        dictionary.clear();
        for (int i = 0; i < n; i++) {
            string word;
            cin >> word;
            dictionary.push_back(word);
        }

        string sequence;
        cin >> sequence;

        generateWords(sequence, "", 0);
        cout << "--" << endl;
    }

    return 0;
}