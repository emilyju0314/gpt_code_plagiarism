#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    string message;

    while (cin >> N) {
        if (N == 0) break;

        cin >> message;

        vector<pair<int, int>> swaps(N);
        for (int i = 0; i < N; i++) {
            cin >> swaps[i].first >> swaps[i].second;
        }

        reverse(swaps.begin(), swaps.end());

        for (auto swap : swaps) {
            int a = swap.first - 1;
            int b = swap.second - 1;
            
            swap(message[a], message[b]);
            sort(message.begin() + a + 1, message.begin() + b, greater<char>());
        }

        cout << message << endl;
    }

    return 0;
} 

The code reads the number of swap operations N, the encrypted message, and the pairs of indices indicating the swaps. It reverses the order of swaps and applies them one by one to decrypt the message. Finally, it outputs the decrypted message.