#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int wow_factor = 0;
    int count_w = 0;
    long long result = 0;

    for (char c : s) {
        if (c == 'o') {
            result += count_w * (count_w - 1) / 2;
        } else {
            count_w++;
        }
    }

    result += count_w * (count_w - 1) / 2;
    
    cout << result << endl;

    return 0;
}