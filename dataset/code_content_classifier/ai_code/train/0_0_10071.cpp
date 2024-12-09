#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minReplacements(int n, int k, string s) {
    s = "." + s + "."; // Add extra "." to handle edge cases

    vector<int> locations;
    for(int i = 0; i < n+2; i++) {
        if(s[i] == '*') {
            locations.push_back(i);
        }
    }

    int replacements = 2;
    for(int i = 2; i < locations.size(); i++) {
        if(locations[i] - locations[i-2] > k) {
            replacements += 2;
        } else if(locations[i] - locations[i-1] > k) {
            replacements++;
        }
    }

    return replacements;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        cout << minReplacements(n, k, s) << endl;
    }

    return 0;
}