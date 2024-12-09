#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s, t;
    cin >> s >> t;
    
    string temp = s;
    vector<int> shifts;
    
    for(int i = 0; i < n; i++) {
        size_t pos = temp.find(t[i]);
        
        if(pos == string::npos) {
            cout << -1 << endl;
            return 0;
        }
        
        int num_shifts = pos + 1;
        shifts.push_back(num_shifts);
        
        string new_temp = temp.substr(pos) + temp.substr(0, pos);
        temp = new_temp;
    }
    
    cout << shifts.size() << endl;
    for(int i = 0; i < shifts.size(); i++) {
        cout << shifts[i] << " ";
    }
    
    return 0;
}