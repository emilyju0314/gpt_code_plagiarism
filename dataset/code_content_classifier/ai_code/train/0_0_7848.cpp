#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        unordered_set<string> words;
        unordered_set<string> prefixes;

        for (int i = 0; i < n; i++) {
            string word;
            cin >> word;

            words.insert(word);

            for (int j = 1; j <= word.length(); j++) {
                prefixes.insert(word.substr(0, j));
            }
        }

        int max_words = 0;
        
        for (const string& word : words) {
            if (prefixes.find(word.substr(1)) == prefixes.end()) {
                max_words += word.length();
            }
        }

        cout << max_words << endl;
    }
    
    return 0;
}