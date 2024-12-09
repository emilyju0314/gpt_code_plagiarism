#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int layers = 0;
    for (int i = 0; i <= N; i++) {
        layers += i;
    }

    cout << layers << endl;

    return 0;
}