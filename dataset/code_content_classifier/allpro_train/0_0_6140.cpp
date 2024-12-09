#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isAnagram(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main() {
    string D;
    cin >> D;

    string Z = D;

    for (int i = 0; i < D.size(); i++) {
        if (i+7 < D.size()) {
            string substr = D.substr(i, 8);
            if (isAnagram(substr, "AIDUNYAN")) {
                Z.replace(i, 8, "AIZUNYAN");
            }
        }
    }

    cout << Z << endl;

    return 0;
}