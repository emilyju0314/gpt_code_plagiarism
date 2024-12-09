#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int count[26] = {0};

    for(char c : s) {
        count[c-'a']++;
    }

    int oddCount = 0;
    for(int i = 0; i < 26; i++) {
        if(count[i] % 2 != 0) {
            oddCount++;
        }
    }

    if(oddCount % 2 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}