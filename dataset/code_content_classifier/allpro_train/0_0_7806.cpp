#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    long long result = 0;
    unordered_map<string, int> substr_counts;
    
    for(int i = 0; i < s.size(); i++) {
        string substr = "";
        for(int j = i; j < s.size(); j++) {
            substr += s[j];
            substr_counts[substr]++;
        }
    }
    
    for(auto it : substr_counts) {
        result += (it.second * (it.second + 1)) / 2;
    }
    
    cout << result << endl;
    
    return 0;
}