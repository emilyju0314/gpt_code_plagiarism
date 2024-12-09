#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculatePlayoffs(int n, int m, vector<vector<int>>& results) {
    // Initialize a vector to keep track of the number of wins each team has
    vector<int> wins(n+1, 0);

    // Update number of wins based on the results of the already played matches
    for(int i = 0; i < m; i++) {
        wins[results[i][0]]++;
    }

    // Sort the number of wins in descending order
    sort(wins.begin()+1, wins.end(), greater<int>());

    // Check if the number of wins is the same for all teams
    int count = 1;
    for(int i = 1; i < n && wins[i] == wins[i+1]; i++) {
        count++;
    }

    // If the count is equal to n, then all teams have the same number of wins
    if(count == n) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    while(cin >> n && n != 0) {
        int m;
        cin >> m;

        vector<vector<int>> results(m, vector<int>(2));
        
        for(int i = 0; i < m; i++) {
            cin >> results[i][0] >> results[i][1];
        }

        int numPlayoffs = calculatePlayoffs(n, m, results);
        cout << numPlayoffs << endl;
    }

    return 0;
}