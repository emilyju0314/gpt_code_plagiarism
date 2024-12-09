#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main() {
    string s;
    cin >> s;
    
    int vowels = 0, consonants = 0;
    int maxLen = 0, count = 0;
    
    for(int i=0; i<s.length(); i++) {
        if(isVowel(s[i])) {
            vowels++;
        } else {
            consonants++;
        }
        
        if(vowels <= 2*consonants) {
            int currentLen = i+1;
            if(currentLen > maxLen) {
                maxLen = currentLen;
                count = 1;
            } else if(currentLen == maxLen) {
                count++;
            }
        } else {
            vowels = 0;
            consonants = 0;
        }
    }
    
    if(maxLen == 0) {
        cout << "No solution\n";
    } else {
        cout << maxLen << " " << count << "\n";
    }
    
    return 0;
}