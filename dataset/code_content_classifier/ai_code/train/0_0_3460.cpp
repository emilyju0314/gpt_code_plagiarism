#include <iostream>
using namespace std;

int main() {
    char characters[10] = {'(', ')', '[', ']', '{', '}', '<', '>'};

    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        if (i % 2 == 0) {
            cout << characters[1];
        } else {
            cout << characters[0];
        }
    }

    return 0;
}