#include <iostream>
#include <string>

using namespace std;

int main() {
    string O, E;
    cin >> O >> E;

    string password = "";
    int i = 0, j = 0;

    while (i < O.length() || j < E.length()) {
        if (i < O.length()) {
            password += O[i];
            i++;
        }
        if (j < E.length()) {
            password += E[j];
            j++;
        }
    }

    cout << password << endl;

    return 0;
}