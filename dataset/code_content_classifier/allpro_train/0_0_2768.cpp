#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int replaced = 0;
    int sum = 0;
    
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '+' && sum > N) {
            replaced++;
            sum = 0;
        } else if (isdigit(S[i])) {
            sum = sum * 10 + (S[i] - '0');
        }
    }

    if (sum > N) {
        replaced++;
    }

    if (replaced == 0 && sum > N) {
        cout << -1 << endl;
    } else {
        cout << replaced << endl;
    }

    return 0;
}