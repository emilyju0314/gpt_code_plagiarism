#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int K;
    cin >> K;

    queue<long long> q;
    for (int i = 1; i <= 9; i++) {
        q.push(i);
    }

    long long lunlun;
    for (int i = 0; i < K; i++) {
        lunlun = q.front();
        q.pop();

        int last_digit = lunlun % 10;
        if (last_digit > 0) {
            q.push(lunlun * 10 + last_digit - 1);
        }
        q.push(lunlun * 10 + last_digit);
        if (last_digit < 9) {
            q.push(lunlun * 10 + last_digit + 1);
        }
    }

    cout << lunlun << endl;

    return 0;
}