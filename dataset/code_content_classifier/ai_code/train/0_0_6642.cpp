#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    int count = 0;
    if(N > 0 && M > 0) {
        count = N * M;
    }
    
    cout << count << endl;
    
    return 0;
}