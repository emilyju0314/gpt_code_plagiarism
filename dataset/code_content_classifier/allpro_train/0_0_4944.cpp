#include <iostream>
#include <string>

using namespace std;

string mergeWords(string word1, string word2) {
    int l = 0;
    for(int i=0; i<min(word1.length(), word2.length()); i++) {
        if(word1.substr(word1.length() - i) == word2.substr(0, i)) {
            l = i;
        }
    }
    return word1 + word2.substr(l);
}

int main() {
    int n;
    cin >> n;
    
    string sentence;
    string compressedWord;
    
    for(int i=0; i<n; i++) {
        string word;
        cin >> word;
        
        if(i == 0) {
            sentence = word;
        } else {
            sentence = mergeWords(sentence, word);
        }
    }
    
    cout << sentence << endl;
    
    return 0;
}