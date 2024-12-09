#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSubstring(const string& word, const string& sub) {
    if (word.size() < sub.size()) {
        return false;
    }
    for (int i = 0; i <= word.size() - sub.size(); i++) {
        bool match = true;
        for (int j = 0; j < sub.size(); j++) {
            if (tolower(word[i + j]) != tolower(sub[j])) {
                match = false;
                break;
            }
        }
        if (match) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<string> forbidden(n);
    for (int i = 0; i < n; i++) {
        cin >> forbidden[i];
    }

    string w;
    cin >> w;

    char letter;
    cin >> letter;

    string result = w;

    for (const string& sub : forbidden) {
        for (int i = 0; i < w.size(); i++) {
            int len = 1;
            while (i + len <= w.size()) {
                if (isSubstring(w.substr(i, len), sub)) {
                    for (int j = i; j < i + len; j++) {
                        if (tolower(w[j]) == tolower(letter)) {
                            result[j] = letter;
                        }
                    }
                }
                len++;
            }
        }
    }

    cout << result << endl;

    return 0;
}