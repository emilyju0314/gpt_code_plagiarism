#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Initialize an empty graph
    vector<vector<int>> graph(n + 1);

    // Initialize a vector to keep track of the degrees of the vertices
    vector<int> degrees(n + 1, 0);

    // Initialize a vector to keep track of the edges
    vector<pair<int, int>> edges;

    // Ask n-1 queries to determine the edges
    for (int i = 1; i <= n - 1; i++) {
        cout << "2" << endl;
        cout << "1 2" << endl;
        cout << "3" << endl;
        cout.flush();

        // Read Mikaela's answer
        int pairs;
        cin >> pairs;

        // If Mikaela's answer is 1, then the edge is between vertices 1 and 2
        if (pairs == 1) {
            edges.push_back({1, 2});
            graph[1].push_back(2);
            graph[2].push_back(1);
            degrees[1]++;
            degrees[2]++;
        }
        // If Mikaela's answer is 2, then the edge is between vertices 1 and 3
        else if (pairs == 2) {
            edges.push_back({1, 3});
            graph[1].push_back(3);
            graph[3].push_back(1);
            degrees[1]++;
            degrees[3]++;
        }
        // If Mikaela's answer is 3, then the edge is between vertices 2 and 3
        else {
            edges.push_back({2, 3});
            graph[2].push_back(3);
            graph[3].push_back(2);
            degrees[2]++;
            degrees[3]++;
        }
    }

    // Output ANSWER in a separate line
    cout << "ANSWER" << endl;

    // Output the determined edges
    for (int i = 0; i < n - 1; i++) {
        cout << edges[i].first << " " << edges[i].second << endl;
    }

    return 0;
}