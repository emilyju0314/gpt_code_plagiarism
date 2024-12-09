#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> possibilities(N, 1);

    for (int i = 1; i < N; i++) {
        string input;
        cin >> input;

        int losers = 0;
        for (int j = 0; j < i; j++) {
            if (input[j] == '0') {
                losers++;
            } else {
                possibilities[j] = 0;
            }
        }

        if (losers == i) {
            possibilities[i] = 0;
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (possibilities[i] == 1) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}