#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int count = 0;
    for (int i = 0; i < 1000; i++) {
        string code = to_string(i);
        while (code.length() < 3) {
            code = "0" + code;
        }
        int j = 0;
        for (int k = 0; k < N; k++) {
            if (S[k] == code[j]) {
                j++;
            }
            if (j == 3) {
                count++;
                break;
            }
        }
    }

    cout << count << endl;

    return 0;
}