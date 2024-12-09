#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> sequence(N);
    for(int i = 0; i < N; i++) {
        cin >> sequence[i];
    }

    int maximum_k = 1;
    for(int t = 1; t <= N/2; t++) {
        if(N % t == 0) {
            bool is_k_part = true;
            for(int i = 0; i < N - t; i++) {
                if(sequence[i] != sequence[i + t]) {
                    is_k_part = false;
                    break;
                }
            }
            if(is_k_part) {
                maximum_k = N / t;
                break;
            }
        }
    }

    cout << maximum_k << endl;

    return 0;
}