#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<string, int>> employees(n);
    for (int i = 0; i < n; i++) {
        cin >> employees[i].first >> employees[i].second;
    }
    
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        char sign;
        string name;
        int hours;
        cin >> sign >> name >> hours;
        
        if (sign == '+') {
            bool found = false;
            for (int j = 0; j < n; j++) {
                if (employees[j].first == name) {
                    if (employees[j].second >= 8) {
                        cout << name << " is working hard now." << endl;
                    } else {
                        cout << name << " is not working now." << endl;
                    }
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << name << " is not working now." << endl;
            }
        }
    }
    
    return 0;
}