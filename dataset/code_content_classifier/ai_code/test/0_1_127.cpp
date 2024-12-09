#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string findSmallestPermutation(string S, string T) {
    string result = S;
    sort(result.begin(), result.end());

    for(char c : T) {
        string::iterator it = find(result.begin(), result.end(), c);
        if(it != result.end()) {
            result.erase(it);
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        string S, T;
        cin >> S >> T;

        cout << findSmallestPermutation(S, T) << endl;
    }

    return 0;
}