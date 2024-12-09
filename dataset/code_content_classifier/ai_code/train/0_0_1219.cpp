#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int M;
    string C;
    cin >> M >> C;

    vector<int> original_digits(10, -1); // Mapping from original digits to substituted digits
    vector<int> used_digits(10, 0); // To keep track of used digits

    for (int i = 0; i < C.size(); i++) {
        if (C[i] != '0' && original_digits[C[i] - '0'] == -1) {
            original_digits[C[i] - '0'] = i == 0 ? 1 : 0; // First digit cannot be 0
        }

        if (i == 0 && C[i] == '0') {
            cout << -1 << endl;
            return 0;
        }
    }

    int current_digit = 1;
    for (int i = 0; i < 10; i++) {
        if (original_digits[i] == -1) {
            while (used_digits[current_digit]) {
                current_digit++;
            }
            original_digits[i] = current_digit;
            used_digits[current_digit] = 1;
        }
    }

    long long D = 0;
    for (int i = 0; i < C.size(); i++) {
        D = (D * 10 + original_digits[C[i] - '0']) % (1000000007);
    }

    for (int i = 0; i < original_digits[C[0] - '0']; i++) {
        if ((D + i) % (1000000007) == M) {
            cout << D + i << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;

    return 0;
}