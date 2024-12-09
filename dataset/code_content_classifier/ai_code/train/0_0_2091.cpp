#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Helper function to reverse a prefix of a string
void reversePrefix(string& s, int len) {
    for (int i = 0; i < len / 2; i++) {
        swap(s[i], s[len - i - 1]);
    }
}

// Function to make string a equal to string b using reversals
vector<int> makeStringsEqual(string& a, string& b) {
    int n = a.size();
    vector<int> steps;

    for (int i = 0; i < n; i += 2) {
        if (a[i] != b[i]) {
            // If the characters are different, find the next occurrence of b[i] in a and reverse the prefix
            int j = i + 1;
            while (j < n && a[j] != b[i]) {
                j += 2;
            }
            if (j == n) {
                steps.clear();
                steps.push_back(-1);
                return steps;
            }

            reversePrefix(a, j + 2);
            steps.push_back(j + 2);
        }
    }

    return steps;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;

        vector<int> steps = makeStringsEqual(a, b);
        
        if (steps[0] == -1) {
            cout << -1 << endl;
        } else {
            cout << steps.size() << endl;
            for (int step : steps) {
                cout << step << " ";
            }
            cout << endl;
        }
    }

    return 0;
}