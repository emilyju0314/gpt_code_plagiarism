#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countModestSubstrings(int l, int r, int n) {
    // Create a string of length n with leading zeros
    string s(n, '0');

    // Calculate the number of modest substrings for each length
    vector<int> modestCount(n + 1, 0);
    for (int length = 1; length <= n; length++) {
        int count = min(r - l + 1, (int)pow(10, length));
        modestCount[length] = count;
    }

    // Find the number of modest substrings
    int totalCount = 0;
    for (int i = 1; i <= n; i++) {
        totalCount += modestCount[i];
    }

    return totalCount;
}

int main() {
    int l, r, n;
    cin >> l >> r >> n;

    int count = countModestSubstrings(l, r, n);
    cout << count << endl;

    // Creating the lexicographically smallest string
    string result(n, '0');
    int currentNum = l;
    for (int i = n - 1; i >= 0; i--) {
        if (currentNum == r) {
            result[i] = '0' + currentNum % 10;
            currentNum = l;
        } else {
            result[i] = '0' + currentNum % 10;
            currentNum++;
        }
    }

    cout << result << endl;

    return 0;
}