#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    // Find the next ABC where all digits are the same
    int x = (N + 110) / 111 * 111;

    cout << x << endl;

    return 0;
}