#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    cout << ((N/100 == 7)||((N/10)%10==7)||(N%10==7) ? "Yes" : "No") << endl;
}