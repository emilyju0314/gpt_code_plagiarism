#include <iostream>
#include <string>

using namespace std;

int main() {
    int k;
    string s, t;
    
    cin >> k >> s >> t;

    for (int i = 0; i < k; i++) {
        if (s[i] < t[i]) {
            s[i]++;
            break;
        }
    }

    cout << s << endl;

    return 0;
}