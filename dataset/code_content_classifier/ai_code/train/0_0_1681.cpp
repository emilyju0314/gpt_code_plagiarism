#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> words(n);
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }

    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    
    int result = 0;
    for(int mask = 1; mask < (1 << 24); mask++) {
        unordered_set<char> currentVowels;
        int count = 0;
        
        for(int i = 0; i < 24; i++) {
            if(mask & (1 << i)) {
                currentVowels.insert('a' + i);
            }
        }
        
        for(string word : words) {
            bool isValid = false;
            for(char c : word) {
                if(currentVowels.count(c) > 0) {
                    isValid = true;
                    break;
                }
            }
            if(isValid) {
                count++;
            }
        }
        
        result ^= count * count;
    }
    
    cout << result << endl;

    return 0;
}