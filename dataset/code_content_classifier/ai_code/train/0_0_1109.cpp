#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C, D, E, total_time = 0;
    cin >> A >> B >> C >> D >> E;

    int times[5] = {A, B, C, D, E};
    sort(times, times + 5);

    total_time = times[4] + 10 - times[4] % 10; // time of last dish ordered

    cout << total_time << endl;
    
    return 0;
}