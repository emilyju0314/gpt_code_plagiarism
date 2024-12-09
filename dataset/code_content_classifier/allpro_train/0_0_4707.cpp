#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    cin >> a;

    int n = a.size();

    for (int i = 0; i < n; i++) {
        if (a[i] == '0') {
            a.erase(i, 1);
            break;
        }
    }

    cout << a << endl;

    return 0;
}