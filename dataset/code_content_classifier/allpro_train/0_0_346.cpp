#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(s[j] == '>') {
                cnt++;
            } else {
                break;
            }
        }

        for(int j = n-1; j >= 0; j--) {
            if(s[j] == '<') {
                cnt++;
            } else {
                break;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}