#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    double P;
    cin >> N >> P;

    double prob = 0;
    int num_maps = 0;

    for (int i = 1; i <= N; i++) {
        prob = 1 - pow((N - i) / (double)N, N);
        if (prob >= P) {
            num_maps = i;
            break;
        }
    }

    cout << num_maps << endl;

    return 0;
}