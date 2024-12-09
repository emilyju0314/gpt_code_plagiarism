#include <iostream>
using namespace std;

int main() {
    int N, D1, D2;
    cin >> N >> D1 >> D2;

    int count = 0;
    for(int i = 0; i < 2 * N; i++) {
        for(int j = 0; j < 2 * N; j++) {
            if(count < N * N && (i - j) % D1 != 0 && (i + j) % D2 != 0) {
                cout << i << " " << j << endl;
                count++;
            }
        }
    }

    return 0;
}