#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool crosswordPossible(vector<string>& words, vector<string>& crossword) {
    sort(words.begin(), words.end());
    
    do {
        crossword[0] = words[0];
        crossword[1] = words[1];
        crossword[2] = words[2];
        crossword[3] = words[3];
        crossword[4] = words[4];
        crossword[5] = words[5];
        
        if (crossword[0][0] == crossword[4][0] && crossword[0][0] == crossword[3][1] 
            && crossword[3][0] == crossword[4][1] && crossword[1][0] == crossword[5][0] 
            && crossword[1][0] == crossword[2][1] && crossword[2][0] == crossword[5][1]) {
            return true;
        }
    } while (next_permutation(words.begin(), words.end()));
    
    return false;
}

int main() {
    vector<string> words(6);
    vector<string> crossword(6, string(6, '.'));
    
    for (int i = 0; i < 6; ++i) {
        cin >> words[i];
    }
    
    if (crosswordPossible(words, crossword)) {
        for (int i = 0; i < 6; ++i) {
            cout << crossword[i] << endl;
        }
    } else {
        cout << "Impossible" << endl;
    }
    
    return 0;
}