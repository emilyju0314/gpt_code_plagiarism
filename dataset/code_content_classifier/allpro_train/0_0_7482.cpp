#include <iostream>
#include <string>
using namespace std;

int main() {
    string n;
    cin >> n;

    int sum = 0;
    for (int i = 1; i <= 4; i++) {
        int num = n[n.size() - 1] - '0';
        sum += num;
        n = n.substr(0, n.size() - 1);
    }

    cout << sum % 5;

    return 0;
}