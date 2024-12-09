#include <iostream>

using namespace std;

int main() {
    int n, b, d;
    cin >> n >> b >> d;

    int totalSize = 0;
    int wasteSectionCount = 0;

    for(int i = 0; i < n; i++) {
        int ai;
        cin >> ai;

        if(ai <= b) {
            totalSize += ai;
        }

        if(totalSize > d) {
            wasteSectionCount++;
            totalSize = 0;
        }
    }

    cout << wasteSectionCount << endl;

    return 0;
}