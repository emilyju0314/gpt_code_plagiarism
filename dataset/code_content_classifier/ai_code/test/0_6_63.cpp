#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int open = 0;
    int maxPrefixes = 0;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int bal = 0;
        for (char c : s) {
            if (c == '(') {
                bal++;
            } else {
                if (bal > 0) {
                    bal--;
                    maxPrefixes++;
                }
            }
        }

        if (bal > 0) {
            open += bal;
        }
    }

    cout << maxPrefixes + (open / 2) << endl;

    return 0;
}