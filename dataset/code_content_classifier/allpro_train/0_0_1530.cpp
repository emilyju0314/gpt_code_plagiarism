#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int max_elements = 0;
    for (int i = 0; i < n; i++) {
        int lowercase_count = 0;
        bool has_uppercase = false;

        for (int j = i; j < n; j++) {
            if (islower(s[j])) {
                lowercase_count++;
            } else if (isupper(s[j])) {
                has_uppercase = true;
            }

            if (!has_uppercase) {
                max_elements = max(max_elements, lowercase_count);
            } else {
                break;
            }
        }
    }

    cout << max_elements << endl;

    return 0;
}