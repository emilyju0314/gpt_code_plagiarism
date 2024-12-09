#include <iostream>

using namespace std;

int digitalRoot(int num) {
    while (num > 9) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}

int main() {
    int N;
    cin >> N;

    int count = 0;

    for (int A = 1; A <= N; A++) {
        if (A * A % N == 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}