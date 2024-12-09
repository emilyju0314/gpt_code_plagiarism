#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> multiset;

int countMatchingPatterns(string pattern) {
    int count = 0;
    for (string num : multiset) {
        int i = num.size() - 1;
        int j = pattern.size() - 1;
        while (i >= 0 && j >= 0) {
            if (pattern[j] == '0' && (num[i] - '0') % 2 != 0) {
                break;
            }
            if (pattern[j] == '1' && (num[i] - '0') % 2 != 1) {
                break;
            }
            i--;
            j--;
        }
        if (j < 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        char c;
        cin >> c;

        if (c == '+') {
            int num;
            cin >> num;
            multiset.push_back(to_string(num));
        } else if (c == '-') {
            int num;
            cin >> num;
            string numStr = to_string(num);
            for (int i = 0; i < multiset.size(); i++) {
                if (multiset[i] == numStr) {
                    multiset.erase(multiset.begin() + i);
                    break;
                }
            }
        } else if (c == '?') {
            string pattern;
            cin >> pattern;
            cout << countMatchingPatterns(pattern) << endl;
        }
    }

    return 0;
}