#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    if (input.substr(0, 3) == "egg") {
        cout << "egg" << endl;
    } else {
        cout << "chicken" << endl;
    }

    return 0;
}