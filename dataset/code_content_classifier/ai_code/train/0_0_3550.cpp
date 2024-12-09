#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;

    vector<int> A(N);
    int S = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        S += A[i];
    }

    int count = 0;
    for(int i = 0; i < N; i++) {
        int sum = A[i];
        for(int j = (i+1) % N; j != i; j = (j+1) % N) {
            sum += A[j];
            if(sum * 5 >= S && sum + Y >= S / 5)
                count++;
        }
    }

    cout << count << endl;

    return 0;
}