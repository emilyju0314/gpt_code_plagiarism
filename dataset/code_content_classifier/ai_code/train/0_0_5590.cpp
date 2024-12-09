#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int F, I, T;
    cin >> F >> I >> T;

    vector<string> opinions(F);
    for (int i = 0; i < F; i++) {
        cin >> opinions[i];
    }

    vector<int> likes(I, 0);
    for (int i = 0; i < I; i++) {
        for (int j = 0; j < F; j++) {
            if (opinions[j][i] == 'Y') {
                likes[i]++;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < I; i++) {
        if (likes[i] >= T) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}