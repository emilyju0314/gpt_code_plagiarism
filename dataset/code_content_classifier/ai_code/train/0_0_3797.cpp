#include <iostream>
#include <map>

using namespace std;

int main() {
    map<char, int> romanToInt = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    string romanNumeral;
    while (cin >> romanNumeral) {
        int result = 0;
        int prev = 0;

        for (int i = romanNumeral.size() - 1; i >= 0; i--) {
            int current = romanToInt[romanNumeral[i]];
            if (current < prev) {
                result -= current;
            } else {
                result += current;
            }
            prev = current;
        }

        cout << result << endl;
    }

    return 0;
}