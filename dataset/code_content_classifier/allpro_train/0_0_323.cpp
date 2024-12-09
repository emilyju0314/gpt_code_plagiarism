#include <iostream>
using namespace std;

int main() {
    long long N, X;
    cin >> N >> X;

    long long result = 3*(N - 1) - X;
    cout << result << endl;

    return 0;
}