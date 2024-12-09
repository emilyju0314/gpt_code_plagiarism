#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Customer {
    int id;
    int time;
    int timeLeft;
    int interval;
};

int main() {
    int N, T;
    
    while (cin >> N >> T) {
        if (N == 0 && T == 0) break;
        
        vector<Customer> customers(N);
        
        for (int i = 0; i < N; i++) {
            cin >> customers[i].time >> customers[i].timeLeft >> customers[i].interval;
            customers[i].id = i + 1;
        }
        
        priority_queue<int, vector<int>, greater<int>> operators; // Min heap to keep track of operators' availability
        int numOperators = 0;
        int currentTime = 0;
        
        while (!customers.empty()) {
            while (!operators.empty() && operators.top() <= currentTime) {
                operators.pop();
            }
            
            if (operators.size() < numOperators) {
                operators.push(currentTime + customers.front().time);
                customers.erase(customers.begin());
            } else {
                int nextCall = currentTime + customers.front().interval;
                currentTime = min(operators.top(), nextCall);
                if (currentTime == nextCall) {
                    customers.push_back(customers.front());
                }
                
                customers.erase(customers.begin());
                numOperators++;
            }
        }
        
        cout << numOperators << endl;
    }
    
    return 0;
}