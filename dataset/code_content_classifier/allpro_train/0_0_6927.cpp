#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string t;
    cin >> t;

    string s = t;
    for (int i = 1; i < k; i++) {
        s += t.substr(n-1);
    }

    cout << s << endl;

    return 0;
} 

// Example
// Input
// 3 4
// aba
// Output
// ababababa