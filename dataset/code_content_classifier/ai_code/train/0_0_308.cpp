#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

bool isMostFrequentSubstring(string str, string sub) {
    int count = 0;
    size_t pos = 0;
    
    while ((pos = str.find(sub, pos)) != string::npos) {
        count++;
        pos++;
    }
    
    return count >= 2;
}

string findGoodString(vector<string> strings) {
    string concatStr = "";
    for (string s : strings) {
        concatStr += s;
    }
    
    set<string> substrings;
    for (int i = 0; i < concatStr.length(); i++) {
        for (int len = 1; len <= concatStr.length() - i; len++) {
            substrings.insert(concatStr.substr(i, len));
        }
    }
    
    for (string sub : substrings) {
        bool isGood = true;
        for (string s : strings) {
            if (!isMostFrequentSubstring(s, sub)) {
                isGood = false;
                break;
            }
        }
        if (isGood) {
            return sub;
        }
    }
    
    return "NO";
}

int main() {
    int n;
    cin >> n;
    
    vector<string> strings(n);
    
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    
    string result = findGoodString(strings);
    
    if (result == "NO") {
        cout << "NO" << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}