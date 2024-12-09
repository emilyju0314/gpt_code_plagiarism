#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    int beauty = 0;
    for (int i = 0; i < n; i++) {
        string currentString = strings[i];
        int count = 1;
        for (int j = 1; j < currentString.length(); j++) {
            if (currentString[j] == currentString[j - 1]) {
                count++;
            } else {
                beauty = max(beauty, count);
                count = 1;
            }
        }
        beauty = max(beauty, count);
    }

    cout << beauty << endl;

    return 0;
}