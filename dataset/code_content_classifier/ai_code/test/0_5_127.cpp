#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string getSmallestPermutation(string S, string T) {
    int counts[26] = {0};
    for(char c : S) {
        counts[c - 'a']++;
    }

    string result = "";
    for(char c : T) {
        counts[c - 'a'] = 0;
        result += string(1, c);
    }

    for(int i = 0; i < 26; i++) {
        result += string(counts[i], 'a' + i);
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        string S, T;
        cin >> S >> T;

        cout << getSmallestPermutation(S, T) << endl;
    }

    return 0;
}