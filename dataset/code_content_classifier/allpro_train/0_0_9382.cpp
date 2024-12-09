#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<char, int> firstLetters;
    unordered_map<char, int> lastLetters;
    int longestDynasty = 0;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        if (name.length() >= 2) {
            if (name[0] != name.back()) {
                firstLetters[name[0]]++;
                lastLetters[name.back()]++;
            } else {
                firstLetters[name[0]]++;
            }
        } else {
            firstLetters[name[0]]++;
            lastLetters[name[0]]++;
        }
    }

    for (auto letter : lastLetters) {
        if(firstLetters[letter.first] > 0) {
            longestDynasty = max(longestDynasty, firstLetters[letter.first] + letter.second - 1);
        }
    }

    cout << longestDynasty << endl;

    return 0;
}