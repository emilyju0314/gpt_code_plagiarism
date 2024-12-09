#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> words(n);

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    int count = 1; // starting with one word on the screen
    for (int i = 1; i < n; i++) {
        if (words[i] - words[i-1] <= c) {
            count++; // the word stays on the screen
        } else {
            count = 1; // starting over with a new word
        }
    }

    cout << count;

    return 0;
}