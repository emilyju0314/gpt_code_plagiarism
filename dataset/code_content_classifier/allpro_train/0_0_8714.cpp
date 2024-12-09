#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    int n = str.length();
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (str[i] == 'Q') {
            for (int j = i + 1; j < n; j++) {
                if (str[j] == 'A') {
                    for (int k = j + 1; k < n; k++) {
                        if (str[k] == 'Q') {
                            count++;
                        }
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}