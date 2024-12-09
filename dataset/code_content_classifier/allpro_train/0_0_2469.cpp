#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool containsR(string word) {
    for(char c : word) {
        if(tolower(c) == 'r') {
            return true;
        }
    }
    return false;
}

int main() {
    int m, n;
    cin >> m;

    vector<string> initialEssay(m);
    for(int i = 0; i < m; i++) {
        cin >> initialEssay[i];
    }

    cin >> n;

    unordered_map<string, string> synonymDictionary;
    for(int i = 0; i < n; i++) {
        string x, y;
        cin >> x >> y;
        synonymDictionary[x] = y;
    }

    int minR = 1e9, minLength = 1e9;

    for(auto word : initialEssay) {
        int currentR = containsR(word) ? 1 : 0;
        int currentLength = word.size();

        for(auto synPair : synonymDictionary) {
            string replacedWord = word;
            size_t pos = replacedWord.find(synPair.first);
            if(pos != string::npos) {
                replacedWord.replace(pos, synPair.first.size(), synPair.second);
                int newR = currentR + containsR(replacedWord);
                int newLength = currentLength - synPair.first.size() + synPair.second.size();

                if(newR < minR) {
                    minR = newR;
                    minLength = newLength;
                }
                else if(newR == minR && newLength < minLength) {
                    minLength = newLength;
                }
            }
        }
    }

    cout << minR << " " << minLength << endl;

    return 0;
}