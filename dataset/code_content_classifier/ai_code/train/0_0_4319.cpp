#include <iostream>
using namespace std;

int main() {
    int max_temp, min_temp;

    for (int i = 0; i < 7; i++) {
        cin >> max_temp >> min_temp;
        cout << max_temp - min_temp << endl;
    }

    return 0;
}