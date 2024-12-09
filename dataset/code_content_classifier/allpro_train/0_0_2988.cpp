#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    
    string cipher;
    cin >> cipher;
    
    cin >> m;
    
    vector<string> words(m);
    for(int i = 0; i < m; i++) {
        cin >> words[i];
    }
    
    string reversed_cipher;
    for(int i = n-1; i >= 0; i--) {
        reversed_cipher += cipher[i];
    }
    
    vector<string> candidates;
    
    string current_word = "";
    for(int i = 0; i < n; i++) {
        if(reversed_cipher[i] != ' ') {
            current_word += reversed_cipher[i];
        } else {
            candidates.push_back(current_word);
            current_word = "";
        }
    }
    candidates.push_back(current_word);
    
    vector<string> solution;
    for(string candidate : candidates) {
        for(string word : words) {
            if(candidate == word) {
                solution.push_back(candidate);
                break;
            }
        }
    }
    
    for(int i = 0; i < solution.size(); i++) {
        cout << solution[i];
        if(i != solution.size() - 1) {
            cout << " ";
        }
    }
    
    return 0;
}