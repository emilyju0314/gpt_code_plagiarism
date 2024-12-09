#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string swapDigits(string a) {
    for (int i = 0; i < a.size(); i++) {
        if (i % 2 == 0) {
            if ((a[i] - '0') % 2 == 0) {
                for (int j = i + 1; j < a.size(); j++) {
                    if ((a[j] - '0') % 2 == 1) {
                        swap(a[i], a[j]);
                        return a;
                    }
                }
            }
        } else {
            if ((a[i] - '0') % 2 == 1) {
                for (int j = i + 1; j < a.size(); j++) {
                    if ((a[j] - '0') % 2 == 0) {
                        swap(a[i], a[j]);
                        return a;
                    }
                }
            }
        }
    }
    return a;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string a;
        cin >> a;

        cout << swapDigits(a) << endl;
    }

    return 0;
}