#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    stack<int> speed_limits;
    stack<int> overtakes;
    int num_violations = 0;

    for(int i = 0; i < n; i++) {
        int type, param;
        cin >> type >> param;
        
        if(type == 1) {
            // Polycarp changes the speed of his car
        } else if(type == 3) {
            // Polycarp's car goes past the "speed limit" sign
            if(!speed_limits.empty() && param < speed_limits.top()) {
                num_violations++;
            }
            speed_limits.push(param);
        } else if(type == 4) {
            // Polycarp's car goes past the "overtake is allowed" sign
            while(!overtakes.empty()) {
                overtakes.pop();
            }
        } else if(type == 5) {
            // Polycarp's car goes past the "no speed limit" sign
            while(!speed_limits.empty()) {
                speed_limits.pop();
            }
        } else if(type == 6) {
            // Polycarp's car goes past the "no overtake allowed" sign
            if(!overtakes.empty()) {
                num_violations++;
            }
            overtakes.push(1);
        }
    }
    
    cout << num_violations << endl;
    
    return 0;
}