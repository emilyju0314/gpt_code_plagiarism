#include <iostream>
#include <vector>

using namespace std;

int main() {
    int w, l;
    cin >> w >> l;

    vector<int> stones(w-1);
    for (int i = 0; i < w-1; i++) {
        cin >> stones[i];
    }

    int maxFrogs = 0;
    int curFrogs = 0;
    int curJump = 0;

    for (int i = 0; i < w-1; i++) {
        if (stones[i] > 0) {
            curFrogs++;
            curJump += i+1;
            if (curJump >= l) {
                maxFrogs = max(maxFrogs, curFrogs);
            }
        } else {
            curJump = 0;
            curFrogs = 0;
        }
    }

    cout << maxFrogs << endl;

    return 0;
}