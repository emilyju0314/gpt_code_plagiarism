#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;

    vector<int> redApples(A), greenApples(B), colorlessApples(C);
    for(int i = 0; i < A; i++) {
        cin >> redApples[i];
    }
    for(int i = 0; i < B; i++) {
        cin >> greenApples[i];
    }
    for(int i = 0; i < C; i++) {
        cin >> colorlessApples[i];
    }

    sort(redApples.rbegin(), redApples.rend());
    sort(greenApples.rbegin(), greenApples.rend());

    vector<int> combinedApples;
    for(int i = 0; i < X; i++) {
        combinedApples.push_back(redApples[i]);
    }
    for(int i = 0; i < Y; i++) {
        combinedApples.push_back(greenApples[i]);
    }
    for(int i = 0; i < C; i++) {
        combinedApples.push_back(colorlessApples[i]);
    }

    sort(combinedApples.rbegin(), combinedApples.rend());

    long long sum = 0;
    for(int i = 0; i < X + Y; i++) {
        sum += combinedApples[i];
    }

    cout << sum << endl;

    return 0;
}