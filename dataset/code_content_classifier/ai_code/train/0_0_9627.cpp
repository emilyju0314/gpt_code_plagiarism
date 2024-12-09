#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool isBeautiful(string word1, string word2) {
    unordered_map<char, int> vowelCount1, vowelCount2;
    char lastVowel1, lastVowel2;

    for (char c : word1) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowelCount1[c]++;
            lastVowel1 = c;
        }
    }

    for (char c : word2) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowelCount2[c]++;
            lastVowel2 = c;
        }
    }

    if (vowelCount1.size() != vowelCount2.size()) return false;
    if (lastVowel1 != lastVowel2) return false;

    for (auto it : vowelCount1) {
        if (vowelCount2.find(it.first) == vowelCount2.end() || vowelCount2[it.first] != it.second) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    unordered_map<string, int> wordCount;

    for (int i = 0; i < n; i++) {
        cin >> words[i];
        wordCount[words[i]]++;
    }

    int beautifulLyrics = 0;
    vector<pair<string, string>> result;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (wordCount[words[i]] > 0 && wordCount[words[j]] > 0 && isBeautiful(words[i], words[j])) {
                beautifulLyrics++;
                result.push_back(make_pair(words[i], words[j]));
                wordCount[words[i]]--;
                wordCount[words[j]]--;
            }
        }
    }

    cout << beautifulLyrics << endl;
    for (auto lyric : result) {
        cout << lyric.first << " " << lyric.second << endl;
    }

    return 0;
}