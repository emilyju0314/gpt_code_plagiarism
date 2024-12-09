#include <iostream>
#include <string>
using namespace std;

char encode(char x,int a,int b){
	return ( ( a * (x-'a') + b) % 26 ) + 'a';
}

char decode(char x, int a, int b){
	int t = ( x - 'a') - b;
	while( (t%a) != 0 ) t += 26;
	return (t/a) % 26 + 'a';
}

string encode(string s, int a, int b){
	for(int i =0 ; i<(int)s.size() ; ++i )
		if( s[i] >= 'a' && s[i] <= 'z' )
			s[i] = encode( s[i] , a , b );
	return s;
}

string decode(string s, int a, int b){
	for(int i =0 ; i<(int)s.size() ; ++i )
		if( s[i] >= 'a' && s[i] <= 'z' )
			s[i] = decode( s[i] , a , b );
	return s;
}

int main(){
	int n=1;
	int a[12] = {1,3,5,7,9,11,15,17,19,21,23,25};
	
	string str, s;
	cin >> n;
	getline( cin , str );
	
	for(int i=0 ; i<n ; ++i){
		bool flag = false;
		getline( cin , str );

		for(int i=0 ; i<12 ; ++i){
			for(int j=0 ; j<26 ; j++){
				s = decode( str , a[i] , j );
				if( s.find("this") != string::npos || s.find("that") != string::npos ){
					flag = true;
					break;
				}
			}
			if( flag ) break;
		}
		cout << s << endl;
	} 
}