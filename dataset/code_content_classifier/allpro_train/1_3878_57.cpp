#include <bits/stdc++.h>
using namespace std;
int main() {
int H, W; 
cin >> H >> W; 
char C[123][123] = {'0'}; 
int A[123] = {0}, B[123] = {0}; 
for (int i = 1; i <= H; i++){
  for (int j = 1; j <= W; j++){
cin >> C[i][j]; 
if(C[i][j] == '#') {A[i] ++; 
B[j] ++; 
}
}
}
for (int i = 1; i <= H; i++){
if(A[i] != 0){
for (int j = 1; j <= W; j++){
if(B[j] != 0){
cout << C[i][j]; 
}
}
cout << endl; 
}
}
}
