#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    // Calculate the number of ways to choose K consecutive integers
    int ways = N - K + 1;

    cout << ways << endl;

    return 0;
}