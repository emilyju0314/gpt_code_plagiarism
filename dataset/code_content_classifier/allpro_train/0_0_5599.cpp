#include <iostream>
#include <string>

using namespace std;

bool isConsonant(char c) {
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    string word;
    cin >> word;

    string result;
    bool typo = false;

    for (int i = 0; i < word.length(); i++) {
        result += word[i];
        if (isConsonant(word[i])) {
            int count = 1;
            while (i + 1 < word.length() && isConsonant(word[i + 1])) {
                count++;
                i++;
            }
            if (count >= 3) {
                if (count > 3 || word[i] != word[i-1]) {
                    result += " ";
                    typo = true;
                }
            }
        }
    }

    cout << (typo ? result : word) << endl;

    return 0;
}