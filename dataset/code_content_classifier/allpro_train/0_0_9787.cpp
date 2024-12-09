#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int totalTime = 0;
    bool reached = false;

    while(totalTime <= 60) {
        if(totalTime % 60 == c) {
            reached = true;
            break;
        }
        totalTime += a;
        if(totalTime % 60 == c) {
            reached = true;
            break;
        }
        totalTime += b;
    }

    if(reached) {
        cout << totalTime << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}