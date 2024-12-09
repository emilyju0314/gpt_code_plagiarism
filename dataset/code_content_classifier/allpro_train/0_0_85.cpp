#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> votes(n);
    for (int i = 0; i < n; i++) {
        cin >> votes[i];
    }

    int max_votes = *max_element(votes.begin(), votes.end());
    int k = max_votes;
    int total_votes_for_awruk = 0;
    for (int i = 0; i < n; i++) {
        total_votes_for_awruk += k - votes[i];
    }

    while (!(total_votes_for_awruk > n * k - total_votes_for_awruk)) {
        k++;
        total_votes_for_awruk = 0;
        for (int i = 0; i < n; i++) {
            total_votes_for_awruk += k - votes[i];
        }
    }

    cout << k << endl;

    return 0;
}