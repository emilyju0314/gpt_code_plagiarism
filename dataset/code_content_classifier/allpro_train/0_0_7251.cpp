#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> likes(M, 0); // Initialize a vector to store the count of likes for each food

    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;

        vector<int> personLikes(K);
        for (int j = 0; j < K; j++) {
            cin >> personLikes[j];
            likes[personLikes[j] - 1]++; // Increment the count of likes for each food
        }
    }

    int count = 0;
    for (int i = 0; i < M; i++) {
        if (likes[i] == N) { // Check if all N people liked the food
            count++;
        }
    }

    cout << count << endl;

    return 0;
}