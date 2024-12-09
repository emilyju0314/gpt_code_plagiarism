#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int h, n;
    cin >> h >> n;

    int nodes_visited = 0;
    int current_node = 1;
    for(int i = h; i > 0; i--) {
        int midpoint = pow(2, i-1);
        nodes_visited++;
        if(n > midpoint) {
            nodes_visited += pow(2, i) - 1;
            n -= midpoint;
            current_node = current_node * 2 + 1;
        } else {
            nodes_visited += pow(2, i) - 1;
            current_node = current_node * 2;
        }
    }

    cout << nodes_visited << endl;

    return 0;
}