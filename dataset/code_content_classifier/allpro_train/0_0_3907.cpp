#include <iostream>
#include <stack>

using namespace std;

int main() {
    int l;
    cin >> l;
    
    stack<int> loops;
    long long x = 0;
    
    for (int i = 0; i < l; i++) {
        string command;
        cin >> command;
        
        if (command == "for") {
            int n;
            cin >> n;
            loops.push(n);
        } else if (command == "end") {
            loops.pop();
        } else if (command == "add") {
            if (loops.empty()) {
                x++;
                if (x > (1LL << 32) - 1) {
                    cout << "OVERFLOW!!!" << endl;
                    return 0;
                }
            } else {
                long long times = loops.top();
                if (x > ((1LL << 32) - 1) / times) {
                    cout << "OVERFLOW!!!" << endl;
                    return 0;
                }
                x *= times;
            }
        }
    }
    
    cout << x << endl;
    
    return 0;
}