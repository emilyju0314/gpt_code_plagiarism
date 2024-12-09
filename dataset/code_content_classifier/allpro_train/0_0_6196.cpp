#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

bool isRelationValid(const map<string, string>& synonyms, const map<string, string>& opposites, const string& word1, const string& word2) {
    if (synonyms.count(word1) && synonyms.at(word1) == word2) {
        return true;
    }
    if (opposites.count(word1) && opposites.at(word1) == word2) {
        return false;
    }
    // Check transitive relations
    if (synonyms.count(word1) && opposites.count(word1) && isRelationValid(synonyms, opposites, synonyms.at(word1), word2)) {
        return false;
    }
    if (opposites.count(word1) && synonyms.count(word1) && isRelationValid(synonyms, opposites, opposites.at(word1), word2)) {
        return false;
    }
    return true;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<string> words(n);
    map<string, string> synonyms, opposites;

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    for (int i = 0; i < m; ++i) {
        int type;
        string word1, word2;
        cin >> type >> word1 >> word2;

        if (type == 1) {
            synonyms[word1] = word2;
            synonyms[word2] = word1;
        } else {
            opposites[word1] = word2;
            opposites[word2] = word1;
        }

        if (isRelationValid(synonyms, opposites, word1, word2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    for (int i = 0; i < q; ++i) {
        string word1, word2;
        cin >> word1 >> word2;

        if (synonyms.count(word1) && synonyms.at(word1) == word2) {
            cout << 1 << endl;
        } else if (opposites.count(word1) && opposites.at(word1) == word2) {
            cout << 2 << endl;
        } else {
            cout << 3 << endl;
        }
    }

    return 0;
}