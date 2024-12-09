#include <iostream>
#include <string>

using namespace std;

int findLevel(int n, int k, string s) {
    int maxLevel = 0;
    int currentLevel = 0;
    char currentChar = s[0];
    int currentCount = 1;

    for(int i = 1; i < n; i++) {
        if (s[i] == currentChar) {
            currentCount++;
            if (currentCount == k) {
                currentLevel++;
                currentCount = 0;
            }
        } else {
            currentChar = s[i];
            currentCount = 1;
        }
        maxLevel = max(maxLevel, currentLevel);
    }

    return maxLevel;
}

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int result = findLevel(n, k, s);
    cout << result << endl;

    return 0;
}