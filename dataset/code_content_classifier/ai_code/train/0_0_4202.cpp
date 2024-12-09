#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int freq[26] = {0};
    for(char c : s) {
        freq[c - 'a']++;
    }

    int oddCount = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] % 2 != 0) {
            oddCount++;
        }
    }

    if(oddCount > 1) {
        cout << "NO SOLUTION" << endl; // Palindrome not possible
    } else {
        string palindrome = "";
        char oddChar;

        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2 == 1) {
                oddChar = 'a' + i;
            }
            for(int j = 0; j < freq[i] / 2; j++) {
                palindrome += (char)('a' + i);
            }
        }

        string secondHalf = palindrome;
        reverse(secondHalf.begin(), secondHalf.end());

        if(oddCount == 1) {
            palindrome += oddChar;
        }

        palindrome += secondHalf;

        cout << palindrome << endl;
    }

    return 0;
}