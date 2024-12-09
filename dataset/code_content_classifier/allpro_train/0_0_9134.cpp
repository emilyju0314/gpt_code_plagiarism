#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> questions;
    for (int i = 2; i <= n; i *= 2) {
        questions.push_back(i);
    }

    cout << questions.size() << endl;
    for (int i = 0; i < questions.size(); i++) {
        cout << questions[i] << " ";
    }

    return 0;
}