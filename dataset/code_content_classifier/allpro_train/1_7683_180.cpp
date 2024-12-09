// B - ... (Triple Dots)
#include <bits/stdc++.h>
using namespace std;

int main(){
	int K; string S; cin>>K>>S;
	cout<< ((int)S.size()<=K? S: S.substr(0,K) + "...") <<endl;
}
