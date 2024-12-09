#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    while(n--) {
        int start, end;
        cin >> start >> end;
        
        vector<int> pass_stops;
        
        if(start < end) {
            if(start >= 1 && start <= 5) {
                for(int i = start; i <= 5; i++) {
                    pass_stops.push_back(i);
                }
            } else {
                for(int i = start; i <= 9; i++) {
                    pass_stops.push_back(i);
                }
                pass_stops.push_back(0);
                for(int i = 5; i <= end; i++) {
                    pass_stops.push_back(i);
                }
            }
        } else {
            if(start <= 5) {
                for(int i = start; i >= 1; i--) {
                    pass_stops.push_back(i);
                }
            } else {
                for(int i = start; i >= 1; i--) {
                    pass_stops.push_back(i);
                }
                pass_stops.push_back(0);
                for(int i = 9; i >= end; i--) {
                    pass_stops.push_back(i);
                }
            }
        }
        
        for(int i : pass_stops) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}