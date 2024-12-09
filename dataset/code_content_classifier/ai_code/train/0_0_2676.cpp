#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

string decipherMessage(const string& ciphertext, const vector<string>& candidateWords, const map<char, char>& substitutionMap) {
    string plaintext = "";
    
    for (char c : ciphertext) {
        if (c == ' ') {
            plaintext += " ";
        } else if (substitutionMap.find(c) != substitutionMap.end()) {
            plaintext += substitutionMap.at(c);
        }
    }
    
    string decryptedMessage = "";
    string currentWord = "";
    
    for (char c : plaintext) {
        if (c == ' ') {
            if (find(candidateWords.begin(), candidateWords.end(), currentWord) != candidateWords.end()) {
                decryptedMessage += currentWord + " ";
            } else {
                decryptedMessage = "-.";
                break;
            }
            currentWord = "";
        } else {
            currentWord += c;
        }
    }
    
    return decryptedMessage;
}

int main() {
    int n;
    
    while (cin >> n && n != 0) {
        vector<string> candidateWords(n);
        map<char, char> substitutionMap;
        
        for (int i = 0; i < n; i++) {
            cin >> candidateWords[i];
        }
        
        string sequence;
        cin.ignore();
        getline(cin, sequence);
        
        string ciphertext = sequence.substr(0, sequence.length() - 1); // Remove the period at the end
        
        for (string word : candidateWords) {
            for (int i = 0; i < word.length(); i++) {
                substitutionMap[word[i]] = ciphertext[i];
            }
        }
        
        cout << decipherMessage(ciphertext, candidateWords, substitutionMap) << endl;
    }
    
    return 0;
}