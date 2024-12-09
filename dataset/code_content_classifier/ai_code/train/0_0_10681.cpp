#include <iostream>
#include <string>

using namespace std;

int countLuckyDigits(int num) {
    int count = 0;
    while (num > 0) {
        if (num % 10 == 4 || num % 10 == 7) {
            count++;
        }
        num /= 10;
    }
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;

    int count = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (countLuckyDigits(num) <= k) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}