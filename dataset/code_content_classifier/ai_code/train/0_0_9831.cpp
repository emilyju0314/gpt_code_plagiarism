#include <iostream>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    int totalSquares = M * N;
    int maxDominoes = totalSquares / 2;

    cout << maxDominoes << endl;

    return 0;
}