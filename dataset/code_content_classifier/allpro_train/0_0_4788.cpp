#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countPalindromicSubstrings(string s) {
    int n = s.size();
    vector<int> palinCount(n, 0);
    int count = 0;

    for(int i = 0; i < n; i++) {
        int l = i, r = i;
        while(l >= 0 && r < n && s[l] == s[r]) {
            palinCount[r]++;
            l--;
            r++;
        }

        l = i;
        r = i + 1;
        while(l >= 0 && r < n && s[l] == s[r]) {
            palinCount[r]++;
            l--;
            r++;
        }
    }

    for(int i = 1; i < n; i++) {
        palinCount[i] += palinCount[i - 1];
    }

    for(int i = 0; i < n - 1; i++) {
        int countA = palinCount[i];
        int countB = palinCount[n - 1] - palinCount[i];
        count += countA * countB;
    }

    return count;
}

int main() {
    string s;
    cin >> s;

    int palindromicPairs = countPalindromicSubstrings(s);
    cout << palindromicPairs << endl;

    return 0;
}