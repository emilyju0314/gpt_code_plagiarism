#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    double area = N * sin(2 * M_PI / N) / (2 * sin(M_PI / N * K));
    cout << fixed << area << endl;

    return 0;
}