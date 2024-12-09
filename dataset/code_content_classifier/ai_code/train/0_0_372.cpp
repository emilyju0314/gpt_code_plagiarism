#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> psychos(n);
    for(int i = 0; i < n; i++) {
        cin >> psychos[i];
    }

    int steps = 0;
    int current_max_id = 0;
    
    for(int i = 0; i < n; i++) {
        if(psychos[i] > current_max_id) {
            current_max_id = psychos[i];
        } else {
            steps++;
        }
    }
    
    cout << steps << endl;

    return 0;
}