#include <iostream>
#include <string>
using namespace std;

bool isLuckyNumber(int n) {
    string num = to_string(n);
    for (char digit : num) {
        if (digit != '4' && digit != '7') {
            return false;
        }
    }
    return true;
}

int main() {
    int l, r;
    cin >> l >> r;

    long long sum = 0;
    for (int i = l; i <= r; i++) {
        int next = i;
        while (!isLuckyNumber(next)) {
            next++;
        }
        sum += next;
    }

    cout << sum << endl;

    return 0;
}