#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countHeadings(string s1, string s2) {
    vector<int> prefix(s2.size(), 0);
    int j = 0;

    for (int i = 1; i < s2.size(); i++) {
        while (j > 0 && s2[i] != s2[j]) {
            j = prefix[j-1];
        }
        if (s2[i] == s2[j]) {
            j++;
        }
        prefix[i] = j;
    }

    int n = s1.size();
    int m = s2.size();
    int res = 1;
    j = 0;

    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[j]) {
            j++;
        }
        if (j == m) {
            return res;
        }
        if (i < n - 1 && j > 0 && s1[i+1] == s2[j]) {
            j++;
        }
        if (j == m) {
            return res;
        }
        if (i == n-1) {
            i = -1;
            res++;
        }
    }

    return -1;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int result = countHeadings(s1, s2);

    cout << result << endl;

    return 0;
}