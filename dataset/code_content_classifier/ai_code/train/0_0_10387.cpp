#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <bitset>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<string> patterns(n);
        for(int i = 0; i < n; i++) {
            cin >> patterns[i];
        }

        map<char, bool> chordMap;
        for(char c : { '0', '1', '2', '4', '8', '3', '5', '6', '7', '9', 'A', 'B', 'C', 'D', 'E', 'F' }) {
            chordMap[c] = false;
        }

        for(string pattern : patterns) {
            for(int i = 0; i < pattern.size(); i += 2) {
                chordMap[pattern[i]] = true;
            }
        }

        bool isValid = true;
        for(auto it = chordMap.begin(); it != chordMap.end(); ++it) {
            if(it->second) {
                isValid = isValid && it->first == '0' || it->first == '1' || it->first == '2' || it->first == '4' || it->first == '8';
            }
        }

        if(!isValid) {
            cout << "Too complex." << endl;
        } else {
            bitset<16> chordValue;
            for(string pattern : patterns) {
                for(int i = 0; i < pattern.size(); i += 2) {
                    chordValue |= 1 << (pattern[i] - '0');
                }
            }

            string newPattern = "";
            for(char c : { '0', '1', '2', '4', '8', '3', '5', '6', '7', '9', 'A', 'B', 'C', 'D', 'E', 'F' }) {
                if(chordValue.test(c - '0')) {
                    newPattern += c;
                }
            }

            cout << newPattern << endl;
        }
    }

    return 0;
}