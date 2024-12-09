#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> demons(n);
    for (int i = 0; i < n; i++) {
        cin >> demons[i];
    }

    string actions = "";
    int currentPos = 0;
    bool movingLeft = false;

    while (true) {
        if (demons[currentPos] > 0) {
            demons[currentPos]--;
            actions += "A";
        }

        if (movingLeft) {
            actions += "L";
            currentPos--;
        } else {
            actions += "R";
            currentPos++;
        }

        if (currentPos == n || currentPos == -1) {
            break;
        }

        movingLeft = !movingLeft;
    }

    cout << actions << endl;

    return 0;
}