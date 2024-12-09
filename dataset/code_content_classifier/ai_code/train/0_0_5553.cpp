#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main() {
    string t;
    int n;
    cin >> t >> n;

    unordered_map<string, int> freq;
    
    for (size_t i = 0; i < t.length(); i++) {
        for (size_t len = 1; i + len - 1 < t.length(); len++) {
            freq[t.substr(i, len)]++;
        }
    }

    long long result = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        for (auto it1 = freq.begin(); it1 != freq.end(); it1++) {
            for (auto it2 = freq.begin(); it2 != freq.end(); it2++) {
                if (it1->first + it2->first == s) {
                    result += (long long)it1->second * it2->second;
                }
            }
        }
    }
    
    cout << result << endl;

    return 0;
}