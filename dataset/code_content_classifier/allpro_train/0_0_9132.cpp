#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    unordered_map<char, int> keysNeeded;
    
    for(int i = 0; i < s.size(); i += 2) {
        char key = tolower(s[i]);
        char door = s[i+1];
        
        if(keysNeeded.find(key) != keysNeeded.end()) {
            keysNeeded[key]--;
        } else {
            keysNeeded[tolower(door)]++;
        }
    }
    
    int minKeysNeeded = 0;
    for(auto key : keysNeeded) {
        minKeysNeeded += abs(key.second);
    }
    
    cout << minKeysNeeded << endl;
    
    return 0;
}