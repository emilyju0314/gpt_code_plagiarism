#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    for (int i = 0; i < M; i++) {
        string slate;
        cin >> slate;

        unordered_set<string> possibleWords;

        int len = slate.length();
        bool leftSideMissing = slate[0] == '*';
        bool rightSideMissing = slate[len - 1] == '*';
        string wordToMatch = slate.substr(leftSideMissing ? 1 : 0, len - (leftSideMissing ? 1 : 0) - (rightSideMissing ? 1 : 0));

        for (string word : words) {
            if (word.length() == wordToMatch.length()) {
                bool matches = true;
                for (int j = 0; j < wordToMatch.length(); j++) {
                    if (slate[j] != '?' && slate[j] != word[j]) {
                        matches = false;
                        break;
                    }
                }
                if (matches) {
                    possibleWords.insert(word);
                }
            }
        }

        cout << possibleWords.size() << endl;
    }

    return 0;
}