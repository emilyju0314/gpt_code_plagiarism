#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> sequences(n);
    int openCount = 0;
    int closeCount = 0;
    for(int i = 0; i < n; i++) {
        cin >> sequences[i];
        for(char c : sequences[i]) {
            if(c == '(') {
                openCount++;
            } else {
                if(openCount > 0) {
                    openCount--;
                } else {
                    closeCount++;
                }
            }
        }
    }

    int minPrefix = min(openCount, closeCount);

    cout << n - minPrefix << endl;

    return 0;
}