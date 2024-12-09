#include <iostream>
#include <string>

using namespace std;

string findDivisibilityRuleType(int b, int d) {
    if (d % 2 == 0 && d % 4 != 0 && d % 5 != 0 && d % 8 != 0 && d % 10 != 0) {
        return "2-type";
    } else if ((d == 3 && b % 2 != 0) || d == 9) {
        return "3-type";
    } else if (d == 11) {
        return "11-type";
    } else if (d == 6 || (d == 66 && (b % 2 == 0 || b == 2) && (b % 3 == 0 || b == 3) && (b % 11 == 0 || b == 11))) {
        return "6-type";
    } else {
        return "7-type";
    }
}

int findLeastDigits(int b, int d) {
    if (d % 2 == 0) {
        return 1;
    } else if (d % 3 == 0 || d == 9) {
        return 1;
    } else if (d == 11) {
        return 1;
    } else if (d == 6) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int b, d;
    cin >> b >> d;

    string ruleType = findDivisibilityRuleType(b, d);
    int leastDigits = findLeastDigits(b, d);

    cout << ruleType << "\n" << leastDigits << endl;

    return 0;
}