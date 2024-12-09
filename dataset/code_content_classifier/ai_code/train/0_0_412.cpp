#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        
        vector<int> employeeIDs;
        long long totalSales = 0;
        
        for (int i = 0; i < n; i++) {
            int id, p, q;
            cin >> id >> p >> q;
            totalSales += p * q;
            
            if (totalSales >= 1000000) {
                employeeIDs.push_back(id);
            }
        }
        
        if (employeeIDs.empty()) {
            cout << "NA" << endl;
        } else {
            for (int id : employeeIDs) {
                cout << id << endl;
            }
        }
    }
    
    return 0;
}