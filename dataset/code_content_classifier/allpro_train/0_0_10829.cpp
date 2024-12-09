#include <iostream>

using namespace std;

int main() {
    int n, S;
    cin >> n >> S;

    int result = (S + n - 1) / n; // Round up the division result

    cout << result << endl;

    return 0;
}