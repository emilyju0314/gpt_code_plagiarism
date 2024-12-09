#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string colors;
    cin >> colors;

    sort(colors.begin(), colors.end());

    int count = 1;
    do {
        bool valid = true;
        for (int i = 0; i < 5; i++) {
            if (colors[i] == colors[i + 1]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            count++;
        }
    } while(next_permutation(colors.begin(), colors.end()));

    cout << count << endl;

    return 0;
}