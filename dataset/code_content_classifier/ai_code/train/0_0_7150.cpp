#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string direction;
    cin >> direction;

    int total_time = 0;
    int time_to_fall = -1;

    for(int i = 0; i < n; i++) {
        if(direction[i] == 'U') {
            total_time += i + 1;
        } else {
            total_time += n - i;
        }
        
        if(direction[i] == 'U' && direction[i+1] == 'D') {
            time_to_fall = total_time + 1;
        }
    }

    for(int i = 0; i < n; i++) {
        if(direction[i] == 'U') {
            cout << total_time - i << " ";
        } else {
            cout << total_time + n - i << " ";
        }
    }

    cout << time_to_fall;

    return 0;
}