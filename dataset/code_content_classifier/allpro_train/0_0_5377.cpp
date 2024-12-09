#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '8') {
            count++;
        }
    }

    if(count > n/2 || (count == 0 && n%2 == 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}