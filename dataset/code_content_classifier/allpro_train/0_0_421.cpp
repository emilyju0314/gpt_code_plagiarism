#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> words;
vector<string> sentences;
int m;

void generateSentences(string current, int length) {
    if (length == 0) {
        sentences.push_back(current);
        return;
    }

    for (string word : words) {
        generateSentences(current + word, length - word.length());
    }
}

int main() {
    int n, K;
    cin >> n >> m >> K;

    words.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    generateSentences("", m);

    sort(sentences.begin(), sentences.end());

    if (K <= sentences.size()) {
        cout << sentences[K - 1] << endl;
    } else {
        cout << "-" << endl;
    }

    return 0;
}