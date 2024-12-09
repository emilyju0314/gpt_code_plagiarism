#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    int length = sqrt(N);
    while (length * (N / length) != N) {
        length--;
    }

    int width = N / length;
    int perimeter = 2 * (length + width);

    cout << perimeter << endl;

    return 0;
}