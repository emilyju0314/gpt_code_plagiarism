#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int max_ops = 0;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        
        int ops = 0;
        while (A % 2 == 0) {
            A /= 2;
            ops++;
        }
        
        if (ops < max_ops || i == 0) {
            max_ops = ops;
        }
    }

    cout << max_ops << endl;

    return 0;
}