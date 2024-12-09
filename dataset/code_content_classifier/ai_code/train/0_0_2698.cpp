#include <iostream>

using namespace std;

int countBeautifulNumbers(int n) {
    int count = 0;
    for (int i = 1; i <= 9; i++) {
        int num = i;
        while (num <= n) {
            count++;
            num = num * 10 + i;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << countBeautifulNumbers(n) << endl;
    }

    return 0;
}