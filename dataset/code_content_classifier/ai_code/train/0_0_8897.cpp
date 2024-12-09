#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    
    cin >> N >> S;
    
    int min_changes = N;
    int west_count = 0;
    
    for(int i = 0; i < N; i++) {
        if(S[i] == 'W') {
            // Calculate the number of people who have to change direction if the leader faces west
            min_changes = min(min_changes, west_count);
        }
        
        if(S[i] == 'W') {
            west_count++;
        }
    }
    
    cout << min_changes << endl;
    
    return 0;
}