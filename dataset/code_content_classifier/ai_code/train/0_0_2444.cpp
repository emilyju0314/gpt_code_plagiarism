#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a < b;
}

int main() {
    int n;
    cin >> n;

    vector<string> substrings;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cout << "? " << i << " " << j << endl;
            string temp;
            cin >> temp;
            substrings.push_back(temp);
        }
    }

    sort(substrings.begin(), substrings.end(), comp);

    string result = substrings[0];
    for (int i = 1; i < substrings.size(); i++) {
        result += substrings[i][n - 1];
    }

    cout << "! " << result << endl;

    return 0;
}