#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> queues(n);
    for (int i = 0; i < n; i++) {
        cin >> queues[i];
    }

    int entrance = 1;
    int i = 0;
    while (queues[i] > 0) {
        queues[i]--;
        i = (i + 1) % n;
        entrance++;
    }

    cout << entrance << endl;

    return 0;
}