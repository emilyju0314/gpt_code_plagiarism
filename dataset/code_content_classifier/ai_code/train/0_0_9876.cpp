#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int happy = 0;
    int prevNum, currNum;
    cin >> prevNum;
    for (int i = 1; i < N; i++) {
        cin >> currNum;
        if (currNum > prevNum) {
            happy++;
        }
        prevNum = currNum;
    }

    cout << happy << endl;

    return 0;
}