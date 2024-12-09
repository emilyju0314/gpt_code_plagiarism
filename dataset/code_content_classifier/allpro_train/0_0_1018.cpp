#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int sheets = (N + 1) / 2; // Round up to nearest integer
    cout << sheets << endl;

    return 0;
}