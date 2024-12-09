#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m;
    string revealed, hiddenWord;
    
    // Input the length of the hidden word and the revealed letters
    cin >> n >> revealed;
    
    // Input the number of words Polycarpus knows
    cin >> m;
    
    // Input the m words
    vector<string> words(m);
    for (int i = 0; i < m; i++) {
        cin >> words[i];
    }
    
    // Find the hidden word
    for (string word : words) {
        bool valid = true;
        for (int i = 0; i < n; i++) {
            if (revealed[i] != '*' && revealed[i] != word[i]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            hiddenWord = word;
            break;
        }
    }
    
    // Determine the number of letters Polycarpus can tell
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (revealed[i] == '*' && any_of(words.begin(), words.end(), [&](string word){ return word[i] == hiddenWord[i]; })) {
            count++;
        }
    }
    
    // Output the result
    cout << count << endl;
    
    return 0;
}