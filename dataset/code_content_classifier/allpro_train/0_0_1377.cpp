#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> hamming;
    hamming.push_back(1);

    for (int i = 0; i < hamming.size(); i++) {
        if (hamming[i] * 2 <= 1000000) {
            hamming.push_back(hamming[i] * 2);
        }
        if (hamming[i] * 3 <= 1000000) {
            hamming.push_back(hamming[i] * 3);
        }
        if (hamming[i] * 5 <= 1000000) {
            hamming.push_back(hamming[i] * 5);
        }
    }

    sort(hamming.begin(), hamming.end());

    while (true) {
        int m, n;
        cin >> m >> n;

        if (m == 0 && n == 0) {
            break;
        }

        int count = 0;
        for (int i = 0; i < hamming.size(); i++) {
            if (hamming[i] >= m && hamming[i] <= n) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}