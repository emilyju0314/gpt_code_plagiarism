#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isUgly(char a, char b) {
    if(abs(a - b) == 1) {
        return true;
    }
    return false;
}

string rearrangeString(string s) {
    vector<char> result;
    for(char c : s) {
        result.push_back(c);
    }
    sort(result.begin(), result.end());

    for(int i = 0; i < s.length() - 1; i++) {
        if(isUgly(result[i], result[i+1])) {
            return "No answer";
        }
    }

    string ans;
    for(char c : result) {
        ans += c;
    }

    return ans;
}

int main() {
    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {
        string s;
        cin >> s;

        cout << rearrangeString(s) << endl;
    }

    return 0;
}