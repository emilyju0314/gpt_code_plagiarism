#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long K;
    cin >> K;
    
    vector<long long> sequence;
    
    long long current_num = K / 50 + 50;
    long long extra = K % 50;
    for (int i = 0; i < 50; i++) {
        sequence.push_back(current_num - 50 + i + extra);
    }
    
    cout << "50" << endl;
    for (int i = 0; i < 50; i++) {
        cout << sequence[i] << " ";
    }
    
    return 0;
}