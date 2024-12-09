#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareWords(const vector<int>& word1, const vector<int>& word2) {
    int n1 = word1.size();
    int n2 = word2.size();
    
    for(int i = 0; i < min(n1, n2); i++) {
        if(word1[i] != word2[i]) {
            return word1[i] < word2[i];
        }
    }
    
    return n1 <= n2;
}

bool checkSorted(const vector<vector<int>>& words) {
    for(int i = 1; i < words.size(); i++) {
        if(!compareWords(words[i-1], words[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, c;
    cin >> n >> c;
    
    vector<vector<int>> words(n);
    
    for(int i = 0; i < n; i++) {
        int length;
        cin >> length;
        vector<int> word(length);
        
        for(int j = 0; j < length; j++) {
            cin >> word[j];
        }
        
        words[i] = word;
    }
    
    if(checkSorted(words)) {
        cout << "0" << endl;
    } else {
        vector<vector<int>> sortedWords = words;
        sort(sortedWords.begin(), sortedWords.end(), compareWords);
        
        for(int shift = 0; shift < c; shift++) {
            vector<vector<int>> shiftedWords = words;
            
            for(auto& word : shiftedWords) {
                for(int& glyph : word) {
                    glyph = (glyph - 1 + shift) % c + 1;
                }
            }
            
            if(checkSorted(shiftedWords)) {
                cout << shift << endl;
                return 0;
            }
        }
        
        cout << "-1" << endl;
    }
    
    return 0;
}