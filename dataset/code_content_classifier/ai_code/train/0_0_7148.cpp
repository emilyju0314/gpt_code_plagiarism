#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {
        int N, R;
        cin >> N >> R;

        int sum = 0;
        for(int i = 0; i < N-1; i++) {
            int num;
            cin >> num;
            sum += num;
        }

        int guess = sum % N;
        if(guess == 0) {
            guess = N;
        }

        cout << guess << endl;
    }

    return 0;
}