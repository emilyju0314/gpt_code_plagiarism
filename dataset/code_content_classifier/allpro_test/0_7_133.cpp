#include <iostream>
#include <vector>
#include <string>

using namespace std;

string findWord(int n, vector<string>& bigrams) {
    string word = "a";
    for (int i = 0; i < n-2; i++) {
        if (bigrams[i][0] != bigrams[i][1]) {
            if (word.back() == 'a') {
                word.push_back('b');
            } else {
                word.push_back('a');
            }
        } else {
            word.push_back(word.back());
        }
    }
    return word;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> bigrams(n-2);
        for (int i = 0; i < n-2; i++) {
            cin >> bigrams[i];
        }

        string word = findWord(n, bigrams);
        cout << word << endl;
    }

    return 0;
}