#include <iostream>
#include <string>

using namespace std;

int main() {
    string email;
    cin >> email;

    int atCount = 0;
    int dotCount = 0;

    for (char c : email) {
        if (c == 'at') {
            atCount++;
        } else if (c == 'dot') {
            dotCount++;
        }
    }

    if (atCount > 1) {
        while (atCount > 1) {
            email.replace(email.find_first_of("at"), 2, "@");
            atCount--;
        }
    } else if (atCount < 1) {
        email.insert(email.find_last_of("@"), 1, '@');
    }

    if (dotCount > 1) {
        while (dotCount > 1) {
            email.replace(email.find_first_of("dot"), 3, ".");
            dotCount--;
        }
    } else if (dotCount < 1) {
        email.insert(email.find_last_of("."), 1, '.');
    }

    cout << email << endl;

    return 0;
}