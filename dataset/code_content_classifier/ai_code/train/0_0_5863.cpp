#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    int K;
    cin >> S >> K;

    int cnt = 0;
    for (int i = 0; i < S.size() - 1; i++) {
        if (S[i] == S[i + 1]) {
            cnt++;
        }
    }

    if (S.front() == S.back()) {
        int front_cnt = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == S.front()) {
                front_cnt++;
            } else {
                break;
            }
        }

        int back_cnt = 0;
        for (int i = S.size() - 1; i >= 0; i--) {
            if (S[i] == S.back()) {
                back_cnt++;
            } else {
                break;
            }
        }

        if (S.size() == front_cnt) {
            cout << S.size() * K / 2 << endl;
        } else if (front_cnt % 2 == 1 && back_cnt % 2 == 1) {
            cout << S.size() * K - cnt * K - 1 << endl;
        } else {
            cout << S.size() * K - cnt * K << endl;
        }
    } else {
        cout << cnt * K << endl;
    }

    return 0;
}