#include <iostream>
#include <string>

using namespace std;

int main() {
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;

    string result = "";

    if (a3 < a4) {
        cout << "-1" << endl;
        return 0;
    }

    for (int i = 0; i < a3; ++i) {
        result += "47";
        if (a4 > 0) {
            result += "4";
            a4--;
        }
    }

    while (a4 > 0) {
        result += "4";
        a4--;
    }

    for (int i = 0; i < a1 - a3; ++i) {
        result = "4" + result;
    }

    for (int i = 0; i < a2 - a3; ++i) {
        result += "7";
    }

    cout << result << endl;

    return 0;
}