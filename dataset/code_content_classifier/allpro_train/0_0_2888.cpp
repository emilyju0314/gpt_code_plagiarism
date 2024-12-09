#include <iostream>
#include <deque>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> deck;
    queue<int> queue;
    deque<int> stack;

    for (int i = 0; i < n; i++) {
        int command;
        cin >> command;
        
        if (command == 1) {
            int num;
            cin >> num;
            stack.push_back(num);
            cout << "pushStack" << endl;
        } else {
            int kisses = 0;
            cout << 3 << " ";
            if (!deck.empty()) {
                cout << "popFront ";
                kisses += deck.front();
                deck.pop_front();    
            }
            if (!queue.empty()) {
                cout << "popQueue ";
                kisses += queue.front();
                queue.pop();
            }
            if (!stack.empty()) {
                cout << "popStack ";
                kisses += stack.back();
                stack.pop_back();
            }
            cout << endl;
        }
    }

    return 0;
}