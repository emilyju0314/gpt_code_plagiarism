#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    
    int n = s.length();
    
    unordered_set<char> uniqueChars; // to store unique characters in the string
    
    // count the frequency of each character in the string
    int charCount[26] = {0};
    for(char c : s) {
        charCount[c - 'a']++;
        uniqueChars.insert(c);
    }
    
    sort(s.begin(), s.end()); // sort the string
    
    int distinctChars = 0; // to count the number of distinct characters left
    
    // iterate over the unique characters and count how many characters can be deleted
    for(char c : uniqueChars) {
        int freq = charCount[c - 'a'];
        if(freq <= k) {
            k -= freq;
            distinctChars++;
        } else {
            break;
        }
    }
    
    cout << distinctChars << endl;
    
    // print the string with only the distinct characters left
    for(char c : s) {
        if(charCount[c - 'a'] > 0) {
            cout << c;
            charCount[c - 'a']--;
        }
    }

    return 0;
}