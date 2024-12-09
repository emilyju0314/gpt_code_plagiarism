#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Person {
    string name;
    int ancestor;
};

int countDistinctSons(vector<Person>& people, map<int, vector<int>>& children, int node, int k) {
    if (k == 0) {
        return 1;
    }
    int count = 0;
    for (int child : children[node]) {
        count += countDistinctSons(people, children, child, k-1);
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<Person> people(n+1);
    map<int, vector<int>> children;

    for (int i = 1; i <= n; i++) {
        cin >> people[i].name >> people[i].ancestor;
        children[people[i].ancestor].push_back(i);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int v, k;
        cin >> v >> k;
        cout << countDistinctSons(people, children, v, k) - 1 << " ";
    }

    return 0;
}