#include <iostream>
#include <deque>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        deque<int> dequeA, dequeB;

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;

            if (dequeA.empty() || num > dequeA.back()) {
                dequeA.push_back(num);
            } else {
                dequeB.push_front(num);
            }
        }

        // Calculate the number of inversions in the deque
        long long inversions = 0;
        for (int i = dequeA.size() - 1; i >= 0; i--) {
            for (int j = 0; j < dequeB.size(); j++) {
                if (dequeA[i] > dequeB[j]) {
                    inversions++;
                } else {
                    break;
                }
            }
        }

        cout << inversions << endl;
    }

    return 0;
}