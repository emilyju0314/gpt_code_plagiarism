#include<bits/stdc++.h>
using namespace std;

long long int N, ans[101];

int main(){
    cin >> N;
    puts(N >= 7 * (-N & 3) ? "Yes" : "No");
    return 0;
}
