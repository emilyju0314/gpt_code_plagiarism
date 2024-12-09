#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string getLexicographicallySmallestPermutation(string S, string T) {
    unordered_map<char, int> freqS;
    unordered_map<char, int> freqT;
    for(char c : S) {
        freqS[c]++;
    }
    for(char c : T) {
        freqT[c]++;
    }
    
    string result = "";
    
    for(char c : "abc") {
        int num = freqS[c] - freqT[c];
        for(int i = 0; i < num; i++) {
            result += c;
        }
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        string S, T;
        cin >> S >> T;
        
        string result = getLexicographicallySmallestPermutation(S, T);
        cout << result << endl;
    }
    
    return 0;
}