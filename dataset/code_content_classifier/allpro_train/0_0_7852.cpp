#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isAdorable(string s) {
    unordered_map<char, int> freq;
    for(char c : s) {
        freq[c]++;
    }
    
    int maxFreq = 0;
    for(auto it : freq) {
        if(it.second > maxFreq) {
            maxFreq = it.second;
        }
    }
    
    int otherFreq = s.length() - maxFreq;
    
    return maxFreq >= 2 && maxFreq <= otherFreq + 1;
}

int main() {
    string s;
    cin >> s;
    
    if(isAdorable(s)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}