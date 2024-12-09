#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int length = 1;
    long long count = 9;
    long long start = 1;

    while (n > length * count) {
        n -= length * count;
        length++;
        count *= 10;
        start *= 10;
    }

    long long number = start + (n - 1) / length;
    string numberStr = to_string(number);
    cout << numberStr[(n - 1) % length] << endl;

    return 0;
}