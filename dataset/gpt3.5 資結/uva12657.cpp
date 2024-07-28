#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> linkedList;

void moveLeft(int x, int y) {
    // Write your code to move node x to the left of node y in the linked list
}

void moveRight(int x, int y) {
    // Write your code to move node x to the right of node y in the linked list
}

void swapNodes(int x, int y) {
    // Write your code to swap node x and node y in the linked list
}

void printList() {
    // Write your code to print the linked list
}

int main() {
    int n, m, caseNum = 1;

    while (cin >> n >> m) {
        linkedList.clear();
        for (int i = 1; i <= n; i++) {
            linkedList.push_back(i);
        }

        int op, x, y;
        for (int i = 0; i < m; i++) {
            cin >> op;
            if (op == 4) {
                printList();
            }
            else {
                cin >> x >> y;
                if (op == 1) {
                    moveLeft(x, y);
                }
                else if (op == 2) {
                    moveRight(x, y);
                }
                else if (op == 3) {
                    swapNodes(x, y);
                }
            }
        }

        cout << "Case " << caseNum++ << ":" << endl;
        printList();
    }

    return 0;
}