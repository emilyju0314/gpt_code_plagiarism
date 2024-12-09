#include <iostream>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  int A[200000+5];
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  for(int i = 0; i < N - K; i++) {
    cout << (A[i] < A[i+K] ? "Yes" : "No") << endl;
  }
}