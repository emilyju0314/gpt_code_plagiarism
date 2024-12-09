#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> balls(2*N);
    for(int i = 0; i < 2*N; i++) {
        balls[i] = i < N ? 1 : 2; // Red balls are represented by 1 and blue balls by 2
    }

    int redCount = 0;
    for(int i = 0; i < N; i++) {
        vector<int> query(N);
        for(int j = 0; j < N; j++) {
            query[j] = i + j;
        }

        cout << "? ";
        for(int j : query) {
            cout << j + 1 << " ";
        }
        cout << endl;

        char response;
        cin >> response;

        if(response == 'R') {
            redCount++;
        }
    }

    int blueCount = N - redCount;

    vector<int> remainingBalls;
    for(int i = 0; i < 2*N; i++) {
        if(balls[i] == (redCount > blueCount ? 1 : 2)) {
            remainingBalls.push_back(i);
        }
    }

    for(int i = 0; i < N-1; i++) {
        cout << "? " << remainingBalls[i] + 1 << " " << remainingBalls[remainingBalls.size()-1] + 1 << endl;

        char response;
        cin >> response;

        if(response == 'B') {
            break;
        }
    }

    cout << "! ";
    for(int i : remainingBalls) {
        cout << balls[i] << " ";
    }
    cout << endl;

    return 0;
}