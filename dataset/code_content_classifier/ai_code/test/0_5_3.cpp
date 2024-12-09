#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int countDivisibleBy25(string s) {
    int count = 0;
    do {
        if ((s.back() == '5' && s[s.length() - 2] == '5') || (s.back() == '0' && s[s.length() - 2] == '0')) {
            count++;
        }
    } while (next_permutation(s.begin(), s.end()));
    
    return count;
}

int main() {
    string s;
    cin >> s;
    
    vector<char> characters;
    for (char c : s) {
        if (c != 'X') {
            characters.push_back(c);
        }
    }
    
    int result = 0;
    
    do {
        string temp = "";
        for (char c : characters) {
            temp += c;
        }
        
        result += countDivisibleBy25(temp);
        
    } while (next_permutation(characters.begin(), characters.end()));
    
    cout << result << endl;
    
    return 0;
}