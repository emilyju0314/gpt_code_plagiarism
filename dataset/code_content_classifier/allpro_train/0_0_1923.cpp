#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    queue<pair<int, int>> q;
    q.push({1, 1});
    int steps = 0;

    while (!q.empty()) {
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();

            if (a == n || b == n) {
                cout << steps << endl;
                return 0;
            }

            q.push({a+b, b});
            q.push({a, a+b});
        }

        steps++;
    }

    return 0;
}