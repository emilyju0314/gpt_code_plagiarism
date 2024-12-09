#include <iostream>
#include <vector>
using namespace std;

string findWord(int n, vector<string> bigrams) {
    string word = "a";
    for (int i = 0; i < n-2; i++) {
        if (bigrams[i][0] != word.back()) {
            word += bigrams[i][0];
        } else {
            word += bigrams[i][1];
        }
    }
    if (bigrams.back()[0] != word.back()) {
        word += bigrams.back()[0];
    } else {
        word += 'a';
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

        cout << findWord(n, bigrams) << endl;
    }

    return 0;
}