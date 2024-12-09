#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    map<char, int> freq;
    for (char c : S) {
        freq[c]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        pq.push(it->second);
    }

    int total_len = 0;

    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        pq.push(a + b);

        total_len += a + b;
    }

    cout << total_len << endl;

    return 0;
}