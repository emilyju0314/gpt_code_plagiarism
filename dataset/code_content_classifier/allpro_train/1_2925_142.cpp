#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

int main(){
	int n;
	cin >> n;
	lli a,b;
	cin >> a >> b;
	for(int i=0; i<n-1; i++){
		lli sa,sb;
		cin >> sa >> sb;
		lli na = (a+sa-1)/sa*sa;
		lli nb = na/sa *sb;
		if(nb>=b){
			a = na;
			b = nb;
		}else{
			b = (b+sb-1)/sb*sb;
			a = b/sb *sa;
		}
	}
	cout << a+b << endl;
	return 0;
}