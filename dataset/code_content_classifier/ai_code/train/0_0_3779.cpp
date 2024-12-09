#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, int>> commands;
    for(int i = 0; i < 2*n; i++) {
        string operation;
        int box_number;
        cin >> operation;
        if(operation == "add") {
            cin >> box_number;
        }
        commands.push_back(make_pair(operation, box_number));
    }

    stack<int> stack_order;
    unordered_map<int, bool> box_removed;
    int reorder_count = 0;

    for(auto command : commands) {
        if(command.first == "add") {
            stack_order.push(command.second);
        } else {
            if(box_removed.find(command.second) != box_removed.end() && !box_removed[command.second]) {
                box_removed[command.second] = true;
            } else {
                reorder_count++;
                while(!stack_order.empty()) {
                    int top_box = stack_order.top();
                    stack_order.pop();
                    box_removed[top_box] = false;
                    if(top_box == command.second) {
                        break;
                    }
                    reorder_count++;
                }
            }
        }
    }

    cout << reorder_count << endl;

    return 0;
}