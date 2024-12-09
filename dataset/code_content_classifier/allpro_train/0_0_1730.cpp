#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    for (int i = 0; i < Q; i++) {
        string prefix, suffix;
        cin >> prefix >> suffix;

        int count = 0;
        for (string word : words) {
            if (word.substr(0, prefix.size()) == prefix && word.substr(word.size() - suffix.size()) == suffix) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}