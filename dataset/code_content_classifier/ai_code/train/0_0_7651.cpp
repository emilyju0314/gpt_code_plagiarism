#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int countGoodSubstrings(const string& s, const string& goodLetters, int k) {
    int n = s.length();
    vector<int> prefixSum(n + 1, 0);
    unordered_map<int, int> count;
    count[0] = 1;
    
    int goodCount = 0;
    int result = 0;
    
    for(char c : s) {
        int index = c - 'a';
        
        if(goodLetters[index] == '0') {
            goodCount++;
        }
        
        prefixSum[goodCount]++;
        
        for(int i = 0; i <= k; i++) {
            // Increase result by the sum of prefixSum values in the range [goodCount - k, goodCount]
            result += count[goodCount - i];
        }
        
        count[goodCount]++;
    }
    
    return result;
}

int main() {
    string s;
    string goodLetters;
    int k;
    
    cin >> s;
    cin >> goodLetters;
    cin >> k;
    
    cout << countGoodSubstrings(s, goodLetters, k) << endl;
    
    return 0;
}