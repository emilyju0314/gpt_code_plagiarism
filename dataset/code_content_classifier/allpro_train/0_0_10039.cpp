#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string S, T;
    cin >> S >> T;

    vector<int> freqS(26, 0);
    vector<int> freqT(26, 0);

    for(char c : S) {
        freqS[c - 'a']++;
    }

    for(char c : T) {
        freqT[c - 'a']++;
    }

    int replacements = 0;
    for(int i = 0; i < 26; i++) {
        replacements += abs(freqS[i] - freqT[i]);
    }

    cout << replacements << endl;

    return 0;
}