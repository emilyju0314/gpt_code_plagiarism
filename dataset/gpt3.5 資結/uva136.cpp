#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main() {
    long long uglyNumbers[1500];
    set<long long> seen;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    pq.push(1);
    seen.insert(1);

    for (int i = 0; i < 1500; i++) {
        long long curr = pq.top();
        pq.pop();
        uglyNumbers[i] = curr;

        for (int j = 2; j <= 5; j++) {
            long long nextNum = curr * j;
            if (!seen.count(nextNum)) {
                seen.insert(nextNum);
                pq.push(nextNum);
            }
        }
    }

    cout << "The 1500'th ugly number is " << uglyNumbers[1499] << "." << endl;

    return 0;
}