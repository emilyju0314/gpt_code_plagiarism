#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int happyPeople(int N, int K, string S) {
    int maxHappy = 0;

    for (int i = 0; i <= N; i++) {
        string temp = S;

        int happy = 0;
        for (int j = 0; j < i-1; j++) {
            if (temp[j] == temp[j+1]) happy++;
        }

        for (int l = 0; l <= min(i, K); l++) {
            for (int r = i; r <= N; r++) {
                string T = temp;
                int newHappy = happy;
                for (int j = l; j < r; j++) {
                    T[j] = (T[j] == 'L') ? 'R' : 'L';
                    if (j > 0 && T[j] == T[j-1]) {
                        newHappy--;
                    } else if (j < N-1 && T[j] == T[j+1]) {
                        newHappy--;
                    } else if (j > 0 && T[j-1] == T[j+1]) {
                        newHappy++;
                    }
                }
                maxHappy = max(maxHappy, newHappy);
            }
        }
    }

    return maxHappy;
}

int main() {
    int N, K;
    string S;

    cin >> N >> K >> S;

    cout << happyPeople(N, K, S) << endl;

    return 0;
}