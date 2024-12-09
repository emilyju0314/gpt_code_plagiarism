#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<string, vector<int>>> data(n);
    
    for(int i=0; i<n; i++) {
        string ti;
        int ki;
        cin >> ti >> ki;
        
        vector<int> positions(ki);
        for(int j=0; j<ki; j++) {
            cin >> positions[j];
        }
        
        data[i] = make_pair(ti, positions);
    }
    
    string result;
    
    for(auto d : data) {
        string ti = d.first;
        vector<int> positions = d.second;
        int max_position = *max_element(positions.begin(), positions.end());
        
        if(max_position > result.size()) {
            result.resize(max_position, 'a'); // Fill with 'a' until max position
        }
        
        for(int i=0; i<d.first.size(); i++) {
            result[positions[i]-1] = max(result[position[i]-1], d.first[i]); // Update character if necessary
        }
    }
    
    cout << result << endl;
    
    return 0;
}