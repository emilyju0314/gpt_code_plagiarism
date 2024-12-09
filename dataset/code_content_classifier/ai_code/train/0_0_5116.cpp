#include <iostream>
#include <string>

using namespace std;

int countOccurrences(string str, string sub) {
    int count = 0;
    size_t pos = 0;
    while ((pos = str.find(sub, pos)) != string::npos) {
        count++;
        pos += sub.length();
    }
    return count;
}

int main() {
    string c, s, t;
    cin >> c >> s >> t;

    int maxDiff = INT_MIN;

    for (char ch = 'a'; ch <= 'z'; ch++) {
        string cTemp = c;
        for (char& x : cTemp) {
            if (x == '*') {
                x = ch;
            }
        }
        int sCount = countOccurrences(cTemp, s);
        int tCount = countOccurrences(cTemp, t);
        maxDiff = max(maxDiff, sCount - tCount);
    }

    cout << maxDiff << endl;

    return 0;
}