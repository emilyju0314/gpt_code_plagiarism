#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    long long L, A, B, M;
    cin >> L >> A >> B >> M;

    string concatenated;
    for (int i = 0; i < L; i++) {
        concatenated += to_string(A + B*i);
    }

    long long num = stoll(concatenated) % M;

    cout << num << endl;

    return 0;
}