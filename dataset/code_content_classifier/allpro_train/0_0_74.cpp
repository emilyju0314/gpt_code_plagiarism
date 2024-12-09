#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isShortPhrase(vector<string>& words) {
    if (words.size() < 5) {
        return false;
    }

    if (words[0].length() != 5 || words[1].length() != 7) {
        return false;
    }

    int len = words[0].length() + words[1].length();
    int index = 2;

    for (int i = 2; i < words.size(); i++) {
        if (words[i].length() == len) {
            index = i;
            break;
        } else {
            len = (len == 7) ? 5 : 7;
            len += words[i].length();
        }
    }

    if (index + 2 < words.size() && words[index+1].length() == 5 && words[index+2].length() == 7) {
        return true;
    }

    return false;
}

int main() {
    int n;
    
    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        vector<string> words(n);
        for (int i = 0; i < n; i++) {
            cin >> words[i];
        }

        for (int i = 0; i < n; i++) {
            vector<string> temp(words.begin() + i, words.end());

            if (isShortPhrase(temp)) {
                cout << i + 1 << endl;
                break;
            }
        }
    }

    return 0;
}