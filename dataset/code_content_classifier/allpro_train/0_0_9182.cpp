#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<string> input(n);
    unordered_map<string, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> input[i];
        sort(input[i].begin(), input[i].end());
        freq[input[i]]++;
    }

    long long int ans = 0;

    for (int i = 0; i < n; i++) {
        reverse(input[i].begin(), input[i].end());
        int len = input[i].size();

        for (int j = 0; j <= len; j++) {
            string left = input[i].substr(0, j);
            string right = input[i].substr(j);

            if (freq.count(left) && isPalindrome(right) && left != right) {
                ans += freq[left];
            }
        }
    }

    cout << ans << endl;

    return 0;
}