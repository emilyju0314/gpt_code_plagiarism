#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reconstructWord(int n, vector<string> bigrams) {
    string word = "";
    
    // Find the missing bigram and its position
    string missingBigram = "";
    int missingIndex = -1;
    for (int i = 0; i < n-1; i++) {
        if (bigrams[i] == bigrams[i+1]) {
            missingBigram = bigrams[i];
            missingIndex = i;
            break;
        }
    }
    
    // Reconstruct the word
    for (int i = 0; i < missingIndex; i++) {
        word += bigrams[i][0];
    }
    word += missingBigram[0];
    for (int i = missingIndex; i < n-2; i++) {
        if (i != missingIndex) {
            word += bigrams[i][1];
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
        
        vector<string> bigrams(n-1);
        for (int i = 0; i < n-1; i++) {
            cin >> bigrams[i];
        }
        
        string word = reconstructWord(n, bigrams);
        cout << word << endl;
    }
    
    return 0;
}