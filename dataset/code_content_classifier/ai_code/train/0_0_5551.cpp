#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    string result;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 || s[i] != s[i - 1]) {
            result += s[i];
        }
    }

    int deleted = n - result.length();
    
    cout << deleted << endl;
    cout << result << endl;

    return 0;
}