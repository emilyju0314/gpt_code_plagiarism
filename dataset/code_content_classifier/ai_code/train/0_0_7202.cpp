#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    map<char, long long> freq;
    
    // Count the frequency of each character in the string
    for(char c : s) {
        freq[c]++;
    }
    
    long long max_occurrences = 1;
    
    // Calculate occurrences of the secret message by considering all possible subsequences
    for(auto it = freq.begin(); it != freq.end(); ++it) {
        max_occurrences = max(max_occurrences, it->second);
    }
    
    cout << max_occurrences << endl;
    
    return 0;
}