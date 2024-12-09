#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> candies(n);

        for (int j = 0; j < n; j++) {
            cin >> candies[j];
        }

        int moves = 0;
        int alice = 0;
        int bob = 0;
        int aliceTotal = 0;
        int bobTotal = 0;
        int left = 0;
        int right = n-1;

        while (left <= right) {
            if (moves % 2 == 0) {
                int sum = 0;
                while (left <= right && sum <= bobTotal) {
                    sum += candies[left++];
                }
                aliceTotal += sum;
                alice = sum;
            } else {
                int sum = 0;
                while (left <= right && sum <= aliceTotal) {
                    sum += candies[right--];
                }
                bobTotal += sum;
                bob = sum;
            }
            moves++;
        }

        cout << moves << " " << aliceTotal << " " << bobTotal << endl;
    }

    return 0;
}