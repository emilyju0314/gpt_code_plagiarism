#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

    int maxBooks = 0;
    int totalTime = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        totalTime += books[i];

        while (totalTime > t) {
            totalTime -= books[start];
            start++;
        }

        maxBooks = max(maxBooks, i - start + 1);
    }

    cout << maxBooks << endl;

    return 0;
}