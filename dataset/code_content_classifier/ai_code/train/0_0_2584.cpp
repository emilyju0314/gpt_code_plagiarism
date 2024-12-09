#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string line;
    
    while(getline(cin, line)) {
        stringstream ss(line);
        vector<int> lengths;
        
        string segment;
        while(getline(ss, segment, ',')) {
            lengths.push_back(stoi(segment));
        }
        
        int v1 = lengths[10];
        int v2 = lengths[11];
        
        double time = 1.0 * lengths[0] / v1;
        double total_length = 0.0;
        
        for(int i = 1; i <= 9; i++) {
            total_length += lengths[i];
            
            double time_i = total_length / v1;
            
            if(time_i >= time) {
                break;
            }
            
            double time_remaining = time - time_i;
            double distance_remaining = time_remaining * v2;
            
            if(distance_remaining <= lengths[i]) {
                cout << i << endl;
                break;
            }
        }
    }
    
    return 0;
}