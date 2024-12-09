#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    cin >> text;

    int count = 0;
    int n = text.length();

    for (int i = 0; i < n; i++) {
        if (text.substr(i, 5) == "heavy") {
            for (int j = i + 5; j < n; j++) {
                if (text.substr(j, 5) == "metal") {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}