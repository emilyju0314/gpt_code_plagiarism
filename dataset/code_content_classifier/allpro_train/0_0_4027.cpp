#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    int count[26] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < words[i].size(); j++) {
            count[words[i][j] - 'a']++;
        }
    }

    sort(count, count + 26, greater<int>());

    if (count[1] == 0) {
        cout << count[0] << endl;
    } else {
        int result = min(count[0] + count[1], (int) words[0].size());
        cout << result << endl;
    }

    return 0;
} 

The code reads the input, stores the counts of each character in the words, sorts the character counts and calculates the maximum total length of words using at most two distinct letters.