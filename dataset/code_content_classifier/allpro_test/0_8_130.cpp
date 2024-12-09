#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> impostors;
        vector<int> crewmates;
        
        cout << "? 1 2 3" << endl;
        int r;
        cin >> r;
        if (r == 0) {
            impostors.push_back(1);
            impostors.push_back(2);
            impostors.push_back(3);
        } else {
            crewmates.push_back(1);
            crewmates.push_back(2);
            crewmates.push_back(3);
        }
        
        cout << "? 4 5 6" << endl;
        cin >> r;
        if (r == 0) {
            impostors.push_back(4);
            impostors.push_back(5);
            impostors.push_back(6);
        } else {
            crewmates.push_back(4);
            crewmates.push_back(5);
            crewmates.push_back(6);
        }
        
        cout << "? 1 2 4" << endl;
        cin >> r;
        if (r == 0) {
            impostors.push_back(1);
            impostors.push_back(2);
            impostors.push_back(4);
        } else {
            crewmates.push_back(1);
            crewmates.push_back(2);
            crewmates.push_back(4);
        }
        
        int k = n/3;
        
        cout << "! " << k << " ";
        for (int i = 1; i <= n; i++) {
            if (find(impostors.begin(), impostors.end(), i) != impostors.end()) {
                cout << i << " ";
            }
        }
        cout << endl;
        
        cout << flush;
    }
    
    return 0;
}