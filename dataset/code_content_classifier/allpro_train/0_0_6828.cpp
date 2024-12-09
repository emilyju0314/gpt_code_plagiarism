#include <iostream>
#include <unordered_map>

using namespace std;

int getValue(char c) {
    if (c == 'm') {
        return 1000;
    } else if (c == 'c') {
        return 100;
    } else if (c == 'x') {
        return 10;
    } else {
        return 1;
    }
}

int getPairValue(char digit, char c) {
    return getValue(c) * (digit - '0');
}

int mcxiToValue(string mcxi) {
    int value = 0;
    int i = 0;

    while (i < mcxi.size()) {
        if (isdigit(mcxi[i])) {
            value += getPairValue(mcxi[i], mcxi[i+1]);
            i += 2;
        } else {
            value += getValue(mcxi[i]);
            i++;
        }
    }

    return value;
}

void valueToMCXI(int value) {
    unordered_map<int, char> digits = {{1000, 'm'}, {100, 'c'}, {10, 'x'}, {1, 'i'}};
    string result = "";

    for (auto &d: digits) {
        int q = value / d.first;
        if (q > 1) {
            result += to_string(q);
        }
        if (q > 0) {
            result += d.second;
            value %= d.first;
        }
    }

    cout << result << endl;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        string mcxi1, mcxi2;
        cin >> mcxi1 >> mcxi2;

        int value1 = mcxiToValue(mcxi1);
        int value2 = mcxiToValue(mcxi2);

        valueToMCXI(value1 + value2);
    }

    return 0;
}