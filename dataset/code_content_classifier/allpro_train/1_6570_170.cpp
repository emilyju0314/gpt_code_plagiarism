#include <iostream>
using namespace std;

bool isPrime(int n){
	for(int i=6 ; i < n ; i+=7 ){
		if( n%i == 0 ) return false;
	}
	for(int i=8 ; i < n ; i+=7 ){
		if( n%i == 0 ) return false;
	}
	return true;
}

int main(){
	int n;
	while( cin >> n , n != 1 ){
		cout << n << ":";
		for(int i=7 ; i <= n+1 ; i+=7 ){
			if( n%(i-1) == 0 ){
				if( isPrime(i-1) ){
					cout << " " << (i-1);
				}
			}
			if( n%(i+1) == 0 ){
				if( isPrime(i+1) ){
					cout << " " << (i+1);
				}
			}
		}
		cout << endl; 
	}
}