#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string S, T;
        cin >> S >> T;

        vector<int> count(26, 0);
        for(char c : S) {
            count[c - 'a']++;
        }

        string S_prime;
        for(char c : T) {
            if(count[c - 'a'] > 0) {
                S_prime += string(count[c - 'a'], c);
                count[c - 'a'] = 0;
            }
        }

        for(int i = 0; i < 26; i++) {
            if(count[i] > 0) {
                S_prime += string(count[i], 'a' + i);
            }
        }

        cout << S_prime << endl;
    }

    return 0;
}