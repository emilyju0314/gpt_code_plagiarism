#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long factorial(int n) {
    long long res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

string findLexicographicallySmallestString(int n, int k, long long x, string s) {
    vector<int> asteriskPositions;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            asteriskPositions.push_back(i);
        }
    }

    string result(n, 'a');
    for (int i = 0; i < asteriskPositions.size(); i++) {
        long long maxCount = min(x, (long long)k);
        x -= maxCount;
        for (int j = 0; j < maxCount; j++) {
            result[asteriskPositions[i]] = 'b';
            asteriskPositions[i]++;
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        long long x;
        cin >> n >> k >> x;
        string s;
        cin >> s;

        string result = findLexicographicallySmallestString(n, k, x, s);
        cout << result << endl;
    }

    return 0;
}