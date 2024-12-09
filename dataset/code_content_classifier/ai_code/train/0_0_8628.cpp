#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++) {
        indegree[p[i]]++;
    }

    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += indegree[i];
    }

    long long result = total * total;
    for (int i = 0; i < n; i++) {
        result -= indegree[i] * indegree[i];
    }

    cout << result << endl;

    return 0;
}