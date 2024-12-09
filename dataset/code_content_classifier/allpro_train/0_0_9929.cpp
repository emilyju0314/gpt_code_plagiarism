#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    int next;
};

int main() {
    int n, start, x;
    cin >> n >> start >> x;

    vector<Node> nodes(n + 1);
    
    for (int i = 1; i <= n; i++) {
        int value, next;
        cout << "? " << i << endl;
        fflush(stdout);
        cin >> nodes[i].value >> nodes[i].next;
    }

    int current = start;
    int ans = -1;

    while (current != -1) {
        if (nodes[current].value >= x) {
            ans = nodes[current].value;
            break;
        }
        current = nodes[current].next;
    }

    cout << "! " << ans << endl;
    fflush(stdout);

    return 0;
}