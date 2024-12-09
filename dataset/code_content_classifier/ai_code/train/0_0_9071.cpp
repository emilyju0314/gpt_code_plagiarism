#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    long long sum_x = 0, sum_y = 0;
    for(int i=0; i<N; i++) {
        long long x, y;
        cin >> x >> y;
        
        sum_x += x;
        sum_y += y;
    }
    
    long long X = sum_x / N;
    long long Y = sum_y / N;
    
    cout << X << " " << Y << endl;
    
    return 0;
}