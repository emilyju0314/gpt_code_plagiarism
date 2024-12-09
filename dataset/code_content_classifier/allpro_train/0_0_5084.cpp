#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> order(N+1);
    
    for (int i = 1; i <= N; i++) {
        int student_number;
        cin >> student_number;
        
        order[student_number] = i;
    }
    
    for (int i = 1; i <= N; i++) {
        cout << order[i] << " ";
    }
    
    return 0;
}