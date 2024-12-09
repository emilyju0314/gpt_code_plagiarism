#include <iostream>
#include <string>

using namespace std;

bool canMakePalindrome(const string& s) {
    int count[26] = {0};
    for(char c : s) {
        count[c - 'a']++;
    }
    
    int oddCount = 0;
    for(int i = 0; i < 26; i++) {
        if(count[i] % 2 == 1) {
            oddCount++;
        }
    }
    
    // If there is at most 1 odd count, a palindrome can be formed
    return oddCount <= 1;
}

int main() {
    string s;
    cin >> s;
    
    if(canMakePalindrome(s)) {
        if(s.length() % 2 == 0) {
            cout << "Second" << endl;
        } else {
            cout << "First" << endl;
        }
    } else {
        if(s.length() % 2 == 0) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    }
    
    return 0;
}