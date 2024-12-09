#include <iostream>

using namespace std;

int main() {
    int N, A;
    cin >> N >> A;

    if ((N % 500 <= A) && (N >= A * 500)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}