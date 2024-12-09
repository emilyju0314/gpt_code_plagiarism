#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string number;
        cin >> number;

        vector<string> codes(n);
        for(int i = 0; i < n; i++) {
            cin >> codes[i];
        }

        long long seconds = 0;
        for(int i = 0; i < n; i++) {
            int digit = number[i] - '0';
            seconds += (codes[i].find('a' + digit) + 1) + 10 * seconds;
        }

        cout << seconds << endl;
    }

    return 0;
}