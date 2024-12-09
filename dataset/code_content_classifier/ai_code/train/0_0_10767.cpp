#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Create vectors to store feudal relationships and castle attacks
    vector<int> masters(n+1);
    vector<bool> desecrated(n+1, false);
    
    // Read feudal relationships
    for(int i=1; i<=n; i++){
        cin >> masters[i];
    }
    
    int m;
    cin >> m;
    
    // Create queue to store castle attacks
    queue<int> attacks;
    
    // Read castle attacks
    for(int i=1; i<=m; i++){
        int event, a, b, k, y;
        cin >> event;
        
        if(event == 1){
            int c;
            cin >> c;
            desecrated[c] = true;
            attacks.push(c);
        } else {
            cin >> a >> b >> k >> y;
            
            int count = 0;
            bool rested = false;
            
            for(int current = a; current != b; current = masters[current]){
                if(desecrated[current]){
                    count++;
                    if(count == k){
                        rested = true;
                        cout << current << " ";
                        for(int j=0; j<k; j++){
                            desecrated[attacks.front()] = false;
                            attacks.pop();
                        }
                        break;
                    }
                }
            }
            
            if(!rested){
                cout << "-1 ";
            }
        }
    }
    
    return 0;
}