#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    
    int money = 1000;
    int stocks = 0;
    
    for(int i=0; i<N-1; i++) {
        if(A[i] < A[i+1]) {
            stocks += money / A[i];
            money %= A[i];
        } else {
            money += A[i] * stocks;
            stocks = 0;
        }
    }
    
    money += A[N-1] * stocks;
    
    cout << money << endl;
    
    return 0;
}