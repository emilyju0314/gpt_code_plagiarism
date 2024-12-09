#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;

    int len = s.length();
    bool possible = false;
    string result;

    for (int i = 1; i <= len; i++) {
        if (len % i == 0) {
            vector<string> sheets;
            for (int j = 0; j < len; j += i) {
                sheets.push_back(s.substr(j, i));
            }

            sort(sheets.begin(), sheets.end());
            string sheet = sheets[0];
            for (int j = 1; j < sheets.size(); j++) {
                sheet = sheet + sheets[j];
            }

            if (sheet == s) {
                possible = true;
                result = sheets[0];
                break;
            }
        }
    }

    if (!possible) {
        cout << -1 << endl;
    } else {
        int sheets_needed = n / result.length();
        if (n % result.length() != 0) {
            sheets_needed++;
        }

        cout << sheets_needed << endl;
        string final_sheet;
        for (int i = 0; i < n; i++) {
            final_sheet += result[i % result.length()];
        }
        cout << final_sheet << endl;
    }

    return 0;
}