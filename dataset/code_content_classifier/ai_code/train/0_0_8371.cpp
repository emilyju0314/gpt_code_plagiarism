#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> words(N);
    vector<string> patterns(M);

    for(int i = 0; i < N; i++) {
        cin >> words[i];
    }

    for(int i = 0; i < M; i++) {
        cin >> patterns[i];
    }

    for(int i = 0; i < M; i++) {
        int count = 0;
        string pattern = patterns[i];
        for(int j = 0; j < N; j++) {
            string word = words[j];
            if(word.length() != pattern.length()) {
                continue; // Pattern and word lengths do not match
            }

            // Check if the word matches the pattern
            bool match = true;
            for(int k = 0; k < pattern.length(); k++) {
                if(pattern[k] == '?') {
                    continue;
                }
                if(pattern[k] != word[k]) {
                    match = false;
                    break;
                }
            }

            if(match) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}