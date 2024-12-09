#include <iostream>

using namespace std;

int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    int neither = N - (A + B - C);

    cout << neither << endl;

    return 0;
}