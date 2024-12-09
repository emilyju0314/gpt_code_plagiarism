#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int jumps = n * n - n + 1;
    cout << jumps << endl;

    return 0;
}