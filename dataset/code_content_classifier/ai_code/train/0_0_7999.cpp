#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string n;
    cin >> n;

    int count = 0;
    while (stoi(n) > 0) {
        int max_digit = 0;
        for (char c : n) {
            max_digit = max(max_digit, c - '0');
        }
        n = to_string(stoi(n) - max_digit);
        count++;
    }

    cout << count << endl;

    return 0;
}