#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    unordered_map<int, bool> is_question;
    vector<int> questions(k);

    for (int i = 0; i < k; i++) {
        cin >> questions[i];
        is_question[questions[i]] = true;
    }

    int count = 0;

    for (int i = 1; i < n; i++) {
        if (!is_question[i]) {
            count++;
        }
    }

    if (k == 1) {
        cout << count << endl;
    } else {
        for (int i = 0; i < k - 1; i++) {
            if (questions[i] != questions[i + 1]) {
                count -= 1;
            }
        }

        cout << count << endl;
    }

    return 0;
}