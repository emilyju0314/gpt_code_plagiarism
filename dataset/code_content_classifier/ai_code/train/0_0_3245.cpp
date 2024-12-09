#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

vector<int> computePrefixFunction(const string& s) {
    int n = s.size();
    vector<int> prefix(n);
    
    for (int i = 1; i < n; i++) {
        int j = prefix[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = prefix[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        prefix[i] = j;
    }
    
    return prefix;
}

int countOccurrences(const string& s, const string& pattern) {
    string concatenated = pattern + "#" + s;
    vector<int> prefix = computePrefixFunction(concatenated);
    
    int occurrences = 0;
    int patternLength = pattern.size();
    for (int i = patternLength + 1; i < concatenated.size(); i++) {
        if (prefix[i] == patternLength) {
            occurrences++;
        }
    }
    
    return occurrences;
}

int main() {
    string s;
    cin >> s;
    
    string x, y;
    cin >> x >> y;
    
    int numDigits = x.size();
    int halfLength = (numDigits + 1) / 2;
    
    int count = countOccurrences(s, x);
    for (int i = stoi(x) + 1; i <= stoi(y); i++) {
        string current = to_string(i);
        while (current.size() < numDigits) {
            current = "0" + current;
        }
        count = (count + countOccurrences(s, current)) % MOD;
    }
    
    cout << count << endl;
    
    return 0;
}