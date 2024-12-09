#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string findWord(int n, vector<string>& bigrams) {
    string word = "a";
    
    for (int i = 0; i < n - 2; i++) {
        if (bigrams[i][0] != word.back()) {
            word += bigrams[i][0];
        } else {
            word += bigrams[i][1];
        }
    }
    
    if (bigrams.back()[0] != word.back()) {
        word += bigrams.back()[0];
    } else {
        word += bigrams.back()[1];
    }
    
    return word;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        vector<string> bigrams(n-2);
        for (int j = 0; j < n - 2; j++) {
            cin >> bigrams[j];
        }
        
        string word = findWord(n, bigrams);
        cout << word << endl;
    }
    
    return 0;
}