#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int vkCount = 0;
    int kAfterVCount = 0;
    int vBeforeKCount = 0;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'V' && s[i + 1] == 'K') {
            vkCount++;
        } else if (s[i] == 'V' && s[i + 1] != 'K') {
            vBeforeKCount++;
        } else if (s[i] != 'V' && s[i + 1] == 'K') {
            kAfterVCount++;
        }
    }

    int moves = min(vBeforeKCount, kAfterVCount) + vkCount;

    cout << moves << endl;

    return 0;
}