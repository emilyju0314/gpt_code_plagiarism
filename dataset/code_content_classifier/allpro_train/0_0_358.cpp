#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        long long N;
        cin >> N;

        long long left = 1, right = N;
        vector<int> answers;

        while (left < right) {
            long long mid = (left + right) / 2;
            
            cout << "? " << mid << endl;
            int ans;
            cin >> ans;

            if (ans == 0) {
                right = mid;
            } else {
                left = mid + 1;
                answers.push_back(mid);
            }
        }

        cout << "? " << left << endl;
        int last_ans;
        cin >> last_ans;

        if (last_ans == 1) {
            answers.push_back(left);
        }

        cout << "= " << max(*max_element(answers.begin(), answers.end()), 1LL) << endl;
    }

    return 0;
}