#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> visibleKangaroos; // stack to keep track of visible kangaroos
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;

        while (!visibleKangaroos.empty() && visibleKangaroos.top() <= size / 2) {
            visibleKangaroos.pop(); // remove kangaroos that are not visible anymore
        }

        visibleKangaroos.push(size); // push the current kangaroo onto the stack
    }

    cout << visibleKangaroos.size() << endl; // output the optimal number of visible kangaroos

    return 0;
}